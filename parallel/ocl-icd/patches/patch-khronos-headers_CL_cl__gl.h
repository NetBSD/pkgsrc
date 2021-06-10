$NetBSD: patch-khronos-headers_CL_cl__gl.h,v 1.1 2021/06/10 05:55:42 nia Exp $

[PATCH] Updated to support latest Khronos headers.

Signed-off-by: Laurent Carlier <lordheavym@gmail.com>

--- khronos-headers/CL/cl_gl.h.orig	2021-03-30 16:10:38.000000000 +0000
+++ khronos-headers/CL/cl_gl.h
@@ -1,5 +1,5 @@
 /*******************************************************************************
- * Copyright (c) 2008-2020 The Khronos Group Inc.
+ * Copyright (c) 2008-2021 The Khronos Group Inc.
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
@@ -102,21 +102,21 @@ clEnqueueReleaseGLObjects(cl_command_que
 
 
 /* Deprecated OpenCL 1.1 APIs */
-extern CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
+extern CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
 clCreateFromGLTexture2D(cl_context      context,
                         cl_mem_flags    flags,
                         cl_GLenum       target,
                         cl_GLint        miplevel,
                         cl_GLuint       texture,
-                        cl_int *        errcode_ret) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+                        cl_int *        errcode_ret) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
-extern CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
+extern CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
 clCreateFromGLTexture3D(cl_context      context,
                         cl_mem_flags    flags,
                         cl_GLenum       target,
                         cl_GLint        miplevel,
                         cl_GLuint       texture,
-                        cl_int *        errcode_ret) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+                        cl_int *        errcode_ret) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
 /* cl_khr_gl_sharing extension  */
 
@@ -145,13 +145,23 @@ clGetGLContextInfoKHR(const cl_context_p
                       void *                        param_value,
                       size_t *                      param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetGLContextInfoKHR_fn)(
+typedef cl_int (CL_API_CALL *clGetGLContextInfoKHR_fn)(
     const cl_context_properties * properties,
     cl_gl_context_info            param_name,
     size_t                        param_value_size,
     void *                        param_value,
     size_t *                      param_value_size_ret);
 
+/* 
+ *  cl_khr_gl_event extension
+ */
+#define CL_COMMAND_GL_FENCE_SYNC_OBJECT_KHR     0x200D
+
+extern CL_API_ENTRY cl_event CL_API_CALL
+clCreateEventFromGLsyncKHR(cl_context context,
+                           cl_GLsync  sync,
+                           cl_int *   errcode_ret) CL_API_SUFFIX__VERSION_1_1;
+
 #ifdef __cplusplus
 }
 #endif
