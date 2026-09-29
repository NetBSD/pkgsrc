$NetBSD: patch-3d-viewer_3d__rendering_opengl_3d__spheres__gizmo.cpp,v 1.1 2026/09/29 16:11:56 bouyer Exp $

no match for 'operator*' (operand types are 'double' and 'const glm::vec3'
{aka 'const glm::vec<3, float, glm::packed_highp>'})

--- 3d-viewer/3d_rendering/opengl/3d_spheres_gizmo.cpp.orig	2026-05-05 13:32:50.313638521 +0000
+++ 3d-viewer/3d_rendering/opengl/3d_spheres_gizmo.cpp
@@ -145,7 +145,7 @@ void SPHERES_GIZMO::render3dSpheresGizmo
                 for( int i = 0; i <= aSegments; ++i )
                 {
                     float     angle = 2.0f * glm::pi<float>() * i / aSegments;
-                    glm::vec3 dir = cos( angle ) * aCamRight + sin( angle ) * aCamUp;
+                    glm::vec3 dir = cosf( angle ) * aCamRight + sinf( angle ) * aCamUp;
 
                     glm::vec3 outer = aCenter + dir * ( aRadius + thickness * 0.5f );
                     glm::vec3 inner = aCenter + dir * ( aRadius - thickness * 0.5f );
