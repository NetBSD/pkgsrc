$NetBSD: patch-libavutil_opencl.c,v 1.3 2016/01/16 17:04:33 leot Exp $

Fix undeclared identifier error.

--- libavutil/opencl.c.orig	2016-01-15 16:58:37.000000000 +0000
+++ libavutil/opencl.c
@@ -457,7 +457,7 @@ cl_program av_opencl_compile(const char 
     cl_program program = NULL;
 
     LOCK_OPENCL;
-    for (i = 0; i < opencl_ctx.kernel_code_count; i++) {
+    for (int i = 0; i < opencl_ctx.kernel_code_count; i++) {
         // identify a program using a unique name within the kernel source
         ptr = av_stristr(opencl_ctx.kernel_code[i].kernel_string, program_name);
         if (ptr && !opencl_ctx.kernel_code[i].is_compiled) {
