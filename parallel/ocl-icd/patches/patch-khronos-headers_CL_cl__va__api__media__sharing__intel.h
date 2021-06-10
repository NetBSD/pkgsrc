$NetBSD: patch-khronos-headers_CL_cl__va__api__media__sharing__intel.h,v 1.1 2021/06/10 05:55:42 nia Exp $

[PATCH] Updated to support latest Khronos headers.

Signed-off-by: Laurent Carlier <lordheavym@gmail.com>

--- khronos-headers/CL/cl_va_api_media_sharing_intel.h.orig	2021-03-30 16:10:38.000000000 +0000
+++ khronos-headers/CL/cl_va_api_media_sharing_intel.h
@@ -68,16 +68,16 @@ clGetDeviceIDsFromVA_APIMediaAdapterINTE
     cl_va_api_device_set_intel    media_adapter_set,
     cl_uint                       num_entries,
     cl_device_id*                 devices,
-    cl_uint*                      num_devices) CL_EXT_SUFFIX__VERSION_1_2;
+    cl_uint*                      num_devices) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL * clGetDeviceIDsFromVA_APIMediaAdapterINTEL_fn)(
+typedef cl_int (CL_API_CALL * clGetDeviceIDsFromVA_APIMediaAdapterINTEL_fn)(
     cl_platform_id                platform,
     cl_va_api_device_source_intel media_adapter_type,
     void*                         media_adapter,
     cl_va_api_device_set_intel    media_adapter_set,
     cl_uint                       num_entries,
     cl_device_id*                 devices,
-    cl_uint*                      num_devices) CL_EXT_SUFFIX__VERSION_1_2;
+    cl_uint*                      num_devices) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_mem CL_API_CALL
 clCreateFromVA_APIMediaSurfaceINTEL(
@@ -85,14 +85,14 @@ clCreateFromVA_APIMediaSurfaceINTEL(
     cl_mem_flags                  flags,
     VASurfaceID*                  surface,
     cl_uint                       plane,
-    cl_int*                       errcode_ret) CL_EXT_SUFFIX__VERSION_1_2;
+    cl_int*                       errcode_ret) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_mem (CL_API_CALL * clCreateFromVA_APIMediaSurfaceINTEL_fn)(
+typedef cl_mem (CL_API_CALL * clCreateFromVA_APIMediaSurfaceINTEL_fn)(
     cl_context                    context,
     cl_mem_flags                  flags,
     VASurfaceID*                  surface,
     cl_uint                       plane,
-    cl_int*                       errcode_ret) CL_EXT_SUFFIX__VERSION_1_2;
+    cl_int*                       errcode_ret) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clEnqueueAcquireVA_APIMediaSurfacesINTEL(
@@ -101,15 +101,15 @@ clEnqueueAcquireVA_APIMediaSurfacesINTEL
     const cl_mem*                 mem_objects,
     cl_uint                       num_events_in_wait_list,
     const cl_event*               event_wait_list,
-    cl_event*                     event) CL_EXT_SUFFIX__VERSION_1_2;
+    cl_event*                     event) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueAcquireVA_APIMediaSurfacesINTEL_fn)(
+typedef cl_int (CL_API_CALL *clEnqueueAcquireVA_APIMediaSurfacesINTEL_fn)(
     cl_command_queue              command_queue,
     cl_uint                       num_objects,
     const cl_mem*                 mem_objects,
     cl_uint                       num_events_in_wait_list,
     const cl_event*               event_wait_list,
-    cl_event*                     event) CL_EXT_SUFFIX__VERSION_1_2;
+    cl_event*                     event) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clEnqueueReleaseVA_APIMediaSurfacesINTEL(
@@ -118,15 +118,15 @@ clEnqueueReleaseVA_APIMediaSurfacesINTEL
     const cl_mem*                 mem_objects,
     cl_uint                       num_events_in_wait_list,
     const cl_event*               event_wait_list,
-    cl_event*                     event) CL_EXT_SUFFIX__VERSION_1_2;
+    cl_event*                     event) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueReleaseVA_APIMediaSurfacesINTEL_fn)(
+typedef cl_int (CL_API_CALL *clEnqueueReleaseVA_APIMediaSurfacesINTEL_fn)(
     cl_command_queue              command_queue,
     cl_uint                       num_objects,
     const cl_mem*                 mem_objects,
     cl_uint                       num_events_in_wait_list,
     const cl_event*               event_wait_list,
-    cl_event*                     event) CL_EXT_SUFFIX__VERSION_1_2;
+    cl_event*                     event) CL_API_SUFFIX__VERSION_1_2;
 
 #ifdef __cplusplus
 }
