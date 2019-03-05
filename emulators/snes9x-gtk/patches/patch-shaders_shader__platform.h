$NetBSD: patch-shaders_shader__platform.h,v 1.1 2019/03/05 12:12:32 nia Exp $

Include unistd for chdir.

--- shaders/shader_platform.h.orig	2019-02-28 02:36:00.000000000 +0000
+++ shaders/shader_platform.h
@@ -28,6 +28,8 @@
 #define realpath(src, resolved) _fullpath(resolved, src, PATH_MAX)
 #endif
 
+#else
+#include <unistd.h>
 #endif
 
 #endif /* __SHADER_PLATFORM_H */
