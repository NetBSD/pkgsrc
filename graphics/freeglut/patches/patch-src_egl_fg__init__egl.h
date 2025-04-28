$NetBSD: patch-src_egl_fg__init__egl.h,v 1.1 2025/04/28 17:41:46 tnn Exp $

Replace K&R prototype

--- src/egl/fg_init_egl.h.orig	2025-04-28 17:36:43.310481098 +0000
+++ src/egl/fg_init_egl.h
@@ -28,6 +28,7 @@
 
 extern void fghPlatformInitializeEGL();
 extern void fghPlatformCloseDisplayEGL();
-extern void fgPlatformDestroyContext();
-
+#  ifndef EGL_VERSION_1_0
+extern void fgPlatformDestroyContext(SFG_PlatformDisplay, SFG_WindowContextType);
+#  endif
 #endif
