$NetBSD: patch-libavutil_opencl.c,v 1.1 2016/03/05 08:52:23 ryoon Exp $

Fix undeclared identifier error.

--- libavutil/opencl.c.orig	2016-02-15 02:29:42.000000000 +0000
+++ libavutil/opencl.c
@@ -453,7 +453,7 @@ cl_program av_opencl_compile(const char 
     char *log = NULL;
 
     LOCK_OPENCL;
-    for (i = 0; i < opencl_ctx.kernel_code_count; i++) {
+    for (int i = 0; i < opencl_ctx.kernel_code_count; i++) {
         // identify a program using a unique name within the kernel source
         ptr = av_stristr(opencl_ctx.kernel_code[i].kernel_string, program_name);
         if (ptr && !opencl_ctx.kernel_code[i].is_compiled) {
