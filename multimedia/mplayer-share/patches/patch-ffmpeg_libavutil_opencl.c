$NetBSD: patch-ffmpeg_libavutil_opencl.c,v 1.1 2015/11/21 09:47:23 leot Exp $

Fix undeclared identifier error.

--- ffmpeg/libavutil/opencl.c.orig	2015-03-16 19:26:04.000000000 +0000
+++ ffmpeg/libavutil/opencl.c
@@ -423,7 +423,7 @@ cl_program av_opencl_compile(const char 
     cl_program program = NULL;
 
     LOCK_OPENCL;
-    for (i = 0; i < opencl_ctx.kernel_code_count; i++) {
+    for (int i = 0; i < opencl_ctx.kernel_code_count; i++) {
         // identify a program using a unique name within the kernel source
         ptr = av_stristr(opencl_ctx.kernel_code[i].kernel_string, program_name);
         if (ptr && !opencl_ctx.kernel_code[i].is_compiled) {
