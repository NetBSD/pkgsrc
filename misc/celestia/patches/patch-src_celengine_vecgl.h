$NetBSD: patch-src_celengine_vecgl.h,v 1.1 2012/07/03 17:40:36 joerg Exp $

--- src/celengine/vecgl.h.orig	2012-07-03 14:48:42.000000000 +0000
+++ src/celengine/vecgl.h
@@ -89,17 +89,20 @@ inline void glScale(const Vec3f& v)
 
 inline void glLightDirection(GLenum light, const Vec3f& dir)
 {
-    glLightfv(light, GL_POSITION, &(Vec4f(dir.x, dir.y, dir.z, 0.0f).x));
+    Vec4f t(dir.x, dir.y, dir.z, 0.0f);
+    glLightfv(light, GL_POSITION, &t.x);
 }
 
 inline void glLightPosition(GLenum light, const Point3f& pos)
 {
-    glLightfv(light, GL_POSITION, &(Vec4f(pos.x, pos.y, pos.z, 1.0f).x));
+    Vec4f t(pos.x, pos.y, pos.z, 1.0f);
+    glLightfv(light, GL_POSITION, &t.x);
 }
 
 inline void glLightColor(GLenum light, GLenum which, const Vec3f& color)
 {
-    glLightfv(light, which, &(Vec4f(color.x, color.y, color.z, 1.0f).x));
+    Vec4f t(color.x, color.y, color.z, 1.0f);
+    glLightfv(light, which, &t.x);
 }
 
 inline void glLightColor(GLenum light, GLenum which, const Vec4f& color)
@@ -109,15 +112,15 @@ inline void glLightColor(GLenum light, G
 
 inline void glLightColor(GLenum light, GLenum which, const Color& color)
 {
+    Vec4f t(color.red(), color.green(), color.blue(), color.alpha());
     glLightfv(light, which,
-              &(Vec4f(color.red(), color.green(), color.blue(), color.alpha()).x));
+              &t.x);
 }
 
 inline void glAmbientLightColor(const Color& color)
 {
-    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,
-                   &(Vec4f(color.red(), color.green(), color.blue(),
-                           color.alpha()).x));
+    Vec4f t(color.red(), color.green(), color.blue(), color.alpha());
+    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, &t.x);
 }
 
 #endif // _VECGL_H_
