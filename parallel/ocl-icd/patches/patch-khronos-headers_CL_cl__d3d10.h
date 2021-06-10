$NetBSD: patch-khronos-headers_CL_cl__d3d10.h,v 1.1 2021/06/10 05:55:42 nia Exp $

[PATCH] Updated to support latest Khronos headers.

Signed-off-by: Laurent Carlier <lordheavym@gmail.com>

--- khronos-headers/CL/cl_d3d10.h.orig	2021-03-30 16:10:38.000000000 +0000
+++ khronos-headers/CL/cl_d3d10.h
@@ -75,7 +75,7 @@ typedef cl_uint cl_d3d10_device_set_khr;
 
 /******************************************************************************/
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetDeviceIDsFromD3D10KHR_fn)(
+typedef cl_int (CL_API_CALL *clGetDeviceIDsFromD3D10KHR_fn)(
     cl_platform_id             platform,
     cl_d3d10_device_source_khr d3d_device_source,
     void *                     d3d_object,
@@ -84,27 +84,27 @@ typedef CL_API_ENTRY cl_int (CL_API_CALL
     cl_device_id *             devices,
     cl_uint *                  num_devices) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateFromD3D10BufferKHR_fn)(
+typedef cl_mem (CL_API_CALL *clCreateFromD3D10BufferKHR_fn)(
     cl_context     context,
     cl_mem_flags   flags,
     ID3D10Buffer * resource,
     cl_int *       errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateFromD3D10Texture2DKHR_fn)(
+typedef cl_mem (CL_API_CALL *clCreateFromD3D10Texture2DKHR_fn)(
     cl_context        context,
     cl_mem_flags      flags,
     ID3D10Texture2D * resource,
     UINT              subresource,
     cl_int *          errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateFromD3D10Texture3DKHR_fn)(
+typedef cl_mem (CL_API_CALL *clCreateFromD3D10Texture3DKHR_fn)(
     cl_context        context,
     cl_mem_flags      flags,
     ID3D10Texture3D * resource,
     UINT              subresource,
     cl_int *          errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueAcquireD3D10ObjectsKHR_fn)(
+typedef cl_int (CL_API_CALL *clEnqueueAcquireD3D10ObjectsKHR_fn)(
     cl_command_queue command_queue,
     cl_uint          num_objects,
     const cl_mem *   mem_objects,
@@ -112,7 +112,7 @@ typedef CL_API_ENTRY cl_int (CL_API_CALL
     const cl_event * event_wait_list,
     cl_event *       event) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueReleaseD3D10ObjectsKHR_fn)(
+typedef cl_int (CL_API_CALL *clEnqueueReleaseD3D10ObjectsKHR_fn)(
     cl_command_queue command_queue,
     cl_uint          num_objects,
     const cl_mem *   mem_objects,
