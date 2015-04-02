$NetBSD: patch-libavutil_opencl.c,v 1.2 2015/04/02 22:40:04 wiz Exp $

Fix undeclared identifier error.

--- libavutil/opencl.c.orig	2015-03-16 19:26:04.000000000 +0000
+++ libavutil/opencl.c
@@ -423,7 +423,7 @@ cl_program av_opencl_compile(const char 
     cl_program program = NULL;
 
     LOCK_OPENCL;
-    for (i = 0; i < opencl_ctx.kernel_code_count; i++) {
+    for (int i = 0; i < opencl_ctx.kernel_code_count; i++) {
         // identify a program using a unique name within the kernel source
         ptr = av_stristr(opencl_ctx.kernel_code[i].kernel_string, program_name);
         if (ptr && !opencl_ctx.kernel_code[i].is_compiled) {
