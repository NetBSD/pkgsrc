$NetBSD: patch-khronos-headers_CL_cl__dx9__media__sharing.h,v 1.1 2021/06/10 05:55:42 nia Exp $

[PATCH] Updated to support latest Khronos headers.

Signed-off-by: Laurent Carlier <lordheavym@gmail.com>

--- khronos-headers/CL/cl_dx9_media_sharing.h.orig	2021-03-30 16:10:38.000000000 +0000
+++ khronos-headers/CL/cl_dx9_media_sharing.h
@@ -76,7 +76,7 @@ typedef struct _cl_dx9_surface_info_khr
 
 /******************************************************************************/
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetDeviceIDsFromDX9MediaAdapterKHR_fn)(
+typedef cl_int (CL_API_CALL *clGetDeviceIDsFromDX9MediaAdapterKHR_fn)(
     cl_platform_id                   platform,
     cl_uint                          num_media_adapters,
     cl_dx9_media_adapter_type_khr *  media_adapter_type,
@@ -86,7 +86,7 @@ typedef CL_API_ENTRY cl_int (CL_API_CALL
     cl_device_id *                   devices,
     cl_uint *                        num_devices) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateFromDX9MediaSurfaceKHR_fn)(
+typedef cl_mem (CL_API_CALL *clCreateFromDX9MediaSurfaceKHR_fn)(
     cl_context                    context,
     cl_mem_flags                  flags,
     cl_dx9_media_adapter_type_khr adapter_type,
@@ -94,7 +94,7 @@ typedef CL_API_ENTRY cl_mem (CL_API_CALL
     cl_uint                       plane,                                                                          
     cl_int *                      errcode_ret) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueAcquireDX9MediaSurfacesKHR_fn)(
+typedef cl_int (CL_API_CALL *clEnqueueAcquireDX9MediaSurfacesKHR_fn)(
     cl_command_queue command_queue,
     cl_uint          num_objects,
     const cl_mem *   mem_objects,
@@ -102,7 +102,7 @@ typedef CL_API_ENTRY cl_int (CL_API_CALL
     const cl_event * event_wait_list,
     cl_event *       event) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueReleaseDX9MediaSurfacesKHR_fn)(
+typedef cl_int (CL_API_CALL *clEnqueueReleaseDX9MediaSurfacesKHR_fn)(
     cl_command_queue command_queue,
     cl_uint          num_objects,
     const cl_mem *   mem_objects,
@@ -159,16 +159,16 @@ clGetDeviceIDsFromDX9INTEL(
     cl_dx9_device_set_intel     dx9_device_set,
     cl_uint                     num_entries,
     cl_device_id*               devices,
-    cl_uint*                    num_devices) CL_EXT_SUFFIX__VERSION_1_1;
+    cl_uint*                    num_devices) CL_API_SUFFIX__VERSION_1_1;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL* clGetDeviceIDsFromDX9INTEL_fn)(
+typedef cl_int (CL_API_CALL* clGetDeviceIDsFromDX9INTEL_fn)(
     cl_platform_id              platform,
     cl_dx9_device_source_intel  dx9_device_source,
     void*                       dx9_object,
     cl_dx9_device_set_intel     dx9_device_set,
     cl_uint                     num_entries,
     cl_device_id*               devices,
-    cl_uint*                    num_devices) CL_EXT_SUFFIX__VERSION_1_1;
+    cl_uint*                    num_devices) CL_API_SUFFIX__VERSION_1_1;
 
 extern CL_API_ENTRY cl_mem CL_API_CALL
 clCreateFromDX9MediaSurfaceINTEL(
@@ -177,15 +177,15 @@ clCreateFromDX9MediaSurfaceINTEL(
     IDirect3DSurface9*          resource,
     HANDLE                      sharedHandle,
     UINT                        plane,
-    cl_int*                     errcode_ret) CL_EXT_SUFFIX__VERSION_1_1;
+    cl_int*                     errcode_ret) CL_API_SUFFIX__VERSION_1_1;
 
-typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateFromDX9MediaSurfaceINTEL_fn)(
+typedef cl_mem (CL_API_CALL *clCreateFromDX9MediaSurfaceINTEL_fn)(
     cl_context                  context,
     cl_mem_flags                flags,
     IDirect3DSurface9*          resource,
     HANDLE                      sharedHandle,
     UINT                        plane,
-    cl_int*                     errcode_ret) CL_EXT_SUFFIX__VERSION_1_1;
+    cl_int*                     errcode_ret) CL_API_SUFFIX__VERSION_1_1;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clEnqueueAcquireDX9ObjectsINTEL(
@@ -194,15 +194,15 @@ clEnqueueAcquireDX9ObjectsINTEL(
     const cl_mem*               mem_objects,
     cl_uint                     num_events_in_wait_list,
     const cl_event*             event_wait_list,
-    cl_event*                   event) CL_EXT_SUFFIX__VERSION_1_1;
+    cl_event*                   event) CL_API_SUFFIX__VERSION_1_1;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueAcquireDX9ObjectsINTEL_fn)(
+typedef cl_int (CL_API_CALL *clEnqueueAcquireDX9ObjectsINTEL_fn)(
     cl_command_queue            command_queue,
     cl_uint                     num_objects,
     const cl_mem*               mem_objects,
     cl_uint                     num_events_in_wait_list,
     const cl_event*             event_wait_list,
-    cl_event*                   event) CL_EXT_SUFFIX__VERSION_1_1;
+    cl_event*                   event) CL_API_SUFFIX__VERSION_1_1;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clEnqueueReleaseDX9ObjectsINTEL(
@@ -211,15 +211,15 @@ clEnqueueReleaseDX9ObjectsINTEL(
     cl_mem*                     mem_objects,
     cl_uint                     num_events_in_wait_list,
     const cl_event*             event_wait_list,
-    cl_event*                   event) CL_EXT_SUFFIX__VERSION_1_1;
+    cl_event*                   event) CL_API_SUFFIX__VERSION_1_1;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueReleaseDX9ObjectsINTEL_fn)(
+typedef cl_int (CL_API_CALL *clEnqueueReleaseDX9ObjectsINTEL_fn)(
     cl_command_queue            command_queue,
     cl_uint                     num_objects,
     cl_mem*                     mem_objects,
     cl_uint                     num_events_in_wait_list,
     const cl_event*             event_wait_list,
-    cl_event*                   event) CL_EXT_SUFFIX__VERSION_1_1;
+    cl_event*                   event) CL_API_SUFFIX__VERSION_1_1;
 
 #ifdef __cplusplus
 }
