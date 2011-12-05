$NetBSD: patch-scenes.h,v 1.1 2011/12/05 22:48:03 joerg Exp $

--- scenes.h.orig	2011-12-05 19:54:48.000000000 +0000
+++ scenes.h
@@ -55,6 +55,6 @@ typedef const struct {
     _base base[SCENE_BASE_MAX];
 } _scene;
 
-extern _scene scene[];
+extern "C" _scene scene[];
 
 #endif // XKOBO_H_SCENES
