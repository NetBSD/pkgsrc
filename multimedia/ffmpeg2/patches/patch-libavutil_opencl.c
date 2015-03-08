$NetBSD: patch-libavutil_opencl.c,v 1.1 2015/03/08 08:10:13 adam Exp $

Fix undeclared identifier error.

--- libavutil/opencl.c.orig	2015-03-08 07:52:00.000000000 +0000
+++ libavutil/opencl.c
@@ -611,7 +611,7 @@ void av_opencl_uninit(void)
         }
         opencl_ctx.context = NULL;
     }
-    for (i = 0; i < opencl_ctx.kernel_code_count; i++) {
+    for (int i = 0; i < opencl_ctx.kernel_code_count; i++) {
         opencl_ctx.kernel_code[i].is_compiled = 0;
     }
     free_device_list(&opencl_ctx.device_list);
