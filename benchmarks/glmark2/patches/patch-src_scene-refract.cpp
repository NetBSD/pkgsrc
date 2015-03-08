$NetBSD: patch-src_scene-refract.cpp,v 1.1 2015/03/08 23:25:39 joerg Exp $

--- src/scene-refract.cpp.orig	2015-03-05 11:02:14.000000000 +0000
+++ src/scene-refract.cpp
@@ -245,10 +245,8 @@ DistanceRenderTarget::teardown()
 {
     program_.stop();
     program_.release();
-    if (tex_) {
-        glDeleteTextures(2, &tex_[0]);
-        tex_[DEPTH] = tex_[COLOR] = 0;
-    }
+    glDeleteTextures(2, &tex_[0]);
+    tex_[DEPTH] = tex_[COLOR] = 0;
     if (fbo_) {
         glDeleteFramebuffers(1, &fbo_);
         fbo_ = 0;
