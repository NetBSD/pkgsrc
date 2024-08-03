$NetBSD: patch-lib_CL_clReleaseCommandBufferKHR.c,v 1.1 2024/08/03 09:54:16 nia Exp $

alloca.h is not portable.

--- lib/CL/clReleaseCommandBufferKHR.c.orig	2024-08-03 09:51:22.289858195 +0000
+++ lib/CL/clReleaseCommandBufferKHR.c
@@ -25,7 +25,11 @@
 #include "pocl_mem_management.h"
 #include "pocl_util.h"
 
+#if defined(__linux) || defined(__sun)
 #include <alloca.h>
+#else
+#include <stdlib.h>
+#endif
 
 CL_API_ENTRY cl_int CL_API_CALL
 POname (clReleaseCommandBufferKHR) (cl_command_buffer_khr command_buffer)
