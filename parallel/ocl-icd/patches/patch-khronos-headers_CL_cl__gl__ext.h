$NetBSD: patch-khronos-headers_CL_cl__gl__ext.h,v 1.1 2021/06/10 05:55:42 nia Exp $

[PATCH] Updated to support latest Khronos headers.

Signed-off-by: Laurent Carlier <lordheavym@gmail.com>

--- khronos-headers/CL/cl_gl_ext.h.orig	2021-03-30 16:10:38.000000000 +0000
+++ khronos-headers/CL/cl_gl_ext.h
@@ -1,5 +1,5 @@
 /*******************************************************************************
- * Copyright (c) 2008-2020 The Khronos Group Inc.
+ * Copyright (c) 2008-2021 The Khronos Group Inc.
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
@@ -14,27 +14,5 @@
  * limitations under the License.
  ******************************************************************************/
 
-#ifndef __OPENCL_CL_GL_EXT_H
-#define __OPENCL_CL_GL_EXT_H
-
-#ifdef __cplusplus
-extern "C" {
-#endif
-
 #include <CL/cl_gl.h>
-
-/* 
- *  cl_khr_gl_event extension
- */
-#define CL_COMMAND_GL_FENCE_SYNC_OBJECT_KHR     0x200D
-
-extern CL_API_ENTRY cl_event CL_API_CALL
-clCreateEventFromGLsyncKHR(cl_context context,
-                           cl_GLsync  sync,
-                           cl_int *   errcode_ret) CL_EXT_SUFFIX__VERSION_1_1;
-
-#ifdef __cplusplus
-}
-#endif
-
-#endif	/* __OPENCL_CL_GL_EXT_H  */
+#pragma message("All OpenGL-related extensions have been moved into cl_gl.h.  Please include cl_gl.h directly.")
