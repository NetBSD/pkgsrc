$NetBSD: patch-shaders_shader__platform.h,v 1.1 2023/11/20 10:19:00 nia Exp $

Add missing include for chdir in Unix.
This appears to be fixed upstream.

--- shaders/shader_platform.h.orig	2023-03-30 16:18:33.000000000 +0000
+++ shaders/shader_platform.h
@@ -28,6 +28,8 @@
 #define realpath(src, resolved) _fullpath(resolved, src, PATH_MAX)
 #endif
 
+#else
+#include <unistd.h>
 #endif
 
 #endif /* __SHADER_PLATFORM_H */
