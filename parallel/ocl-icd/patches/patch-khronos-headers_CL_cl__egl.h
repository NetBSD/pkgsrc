$NetBSD: patch-khronos-headers_CL_cl__egl.h,v 1.1 2021/06/10 05:55:42 nia Exp $

[PATCH] Updated to support latest Khronos headers.

Signed-off-by: Laurent Carlier <lordheavym@gmail.com>

--- khronos-headers/CL/cl_egl.h.orig	2021-03-30 16:10:38.000000000 +0000
+++ khronos-headers/CL/cl_egl.h
@@ -56,7 +56,7 @@ clCreateFromEGLImageKHR(cl_context      
                         const cl_egl_image_properties_khr * properties,
                         cl_int *                    errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateFromEGLImageKHR_fn)(
+typedef cl_mem (CL_API_CALL *clCreateFromEGLImageKHR_fn)(
     cl_context                  context,
     CLeglDisplayKHR             egldisplay,
     CLeglImageKHR               eglimage,
@@ -73,7 +73,7 @@ clEnqueueAcquireEGLObjectsKHR(cl_command
                               const cl_event * event_wait_list,
                               cl_event *       event) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueAcquireEGLObjectsKHR_fn)(
+typedef cl_int (CL_API_CALL *clEnqueueAcquireEGLObjectsKHR_fn)(
     cl_command_queue command_queue,
     cl_uint          num_objects,
     const cl_mem *   mem_objects,
@@ -90,7 +90,7 @@ clEnqueueReleaseEGLObjectsKHR(cl_command
                               const cl_event * event_wait_list,
                               cl_event *       event) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueReleaseEGLObjectsKHR_fn)(
+typedef cl_int (CL_API_CALL *clEnqueueReleaseEGLObjectsKHR_fn)(
     cl_command_queue command_queue,
     cl_uint          num_objects,
     const cl_mem *   mem_objects,
@@ -107,7 +107,7 @@ clCreateEventFromEGLSyncKHR(cl_context  
                             CLeglDisplayKHR display,
                             cl_int *        errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_event (CL_API_CALL *clCreateEventFromEGLSyncKHR_fn)(
+typedef cl_event (CL_API_CALL *clCreateEventFromEGLSyncKHR_fn)(
     cl_context      context,
     CLeglSyncKHR    sync,
     CLeglDisplayKHR display,
