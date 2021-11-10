#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Geometry.h"
#include <vector>
#define I_MVP 0
#define I_MV 1
#define I_MV_LIGHT 2
#define I_NM 3

class Scene{

public:

    Scene() = default;

    ~Scene() = default;

    void initialize();
    
    void render();

    void addGeometry(Geometry*);

    
private:

    glm::mat4x4 toMatrix4x4Row(glm::mat4);

    glm::mat4x4 toMatrix4x4Column(glm::mat4);
    
    glm::mat4x4 toMatrix4x4(glm::mat3);

    std::vector<Geometry*>mGeometries;
    
    std::vector<glm::mat4x4>mSceneMatrices;

    struct LightSource {
        glm::vec3 color;
        glm::vec3 position;
    } mPointLight;

    struct cameraHandler {
    
        float fov = 45.0f;
        float aspectRatio = 4.0f / 3.0f;
        float zoom = 2.0f;
        glm::quat orientation;
        glm::mat4 projectionMatrix;
        glm::mat4 viewMatrix;
    } mCamera;
};
