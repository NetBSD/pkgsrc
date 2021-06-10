$NetBSD: patch-khronos-headers_CL_cl.h,v 1.1 2021/06/10 05:55:42 nia Exp $

[PATCH] Updated to support latest Khronos headers.

Signed-off-by: Laurent Carlier <lordheavym@gmail.com>

--- khronos-headers/CL/cl.h.orig	2021-03-30 16:10:38.000000000 +0000
+++ khronos-headers/CL/cl.h
@@ -1311,11 +1311,11 @@ clLinkProgram(cl_context           conte
 
 #ifdef CL_VERSION_2_2
 
-extern CL_API_ENTRY CL_EXT_PREFIX__VERSION_2_2_DEPRECATED cl_int CL_API_CALL
+extern CL_API_ENTRY CL_API_PREFIX__VERSION_2_2_DEPRECATED cl_int CL_API_CALL
 clSetProgramReleaseCallback(cl_program          program,
                             void (CL_CALLBACK * pfn_notify)(cl_program program,
                                                             void * user_data),
-                            void *              user_data) CL_EXT_SUFFIX__VERSION_2_2_DEPRECATED;
+                            void *              user_data) CL_API_SUFFIX__VERSION_2_2_DEPRECATED;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clSetProgramSpecializationConstant(cl_program  program,
@@ -1857,11 +1857,11 @@ clGetExtensionFunctionAddressForPlatform
     clSetCommandQueueProperty(cl_command_queue              command_queue,
                               cl_command_queue_properties   properties,
                               cl_bool                       enable,
-                              cl_command_queue_properties * old_properties) CL_EXT_SUFFIX__VERSION_1_0_DEPRECATED;
+                              cl_command_queue_properties * old_properties) CL_API_SUFFIX__VERSION_1_0_DEPRECATED;
 #endif /* CL_USE_DEPRECATED_OPENCL_1_0_APIS */
 
 /* Deprecated OpenCL 1.1 APIs */
-extern CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
+extern CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
 clCreateImage2D(cl_context              context,
                 cl_mem_flags            flags,
                 const cl_image_format * image_format,
@@ -1869,9 +1869,9 @@ clCreateImage2D(cl_context              
                 size_t                  image_height,
                 size_t                  image_row_pitch,
                 void *                  host_ptr,
-                cl_int *                errcode_ret) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+                cl_int *                errcode_ret) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
-extern CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
+extern CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
 clCreateImage3D(cl_context              context,
                 cl_mem_flags            flags,
                 const cl_image_format * image_format,
@@ -1881,46 +1881,46 @@ clCreateImage3D(cl_context              
                 size_t                  image_row_pitch,
                 size_t                  image_slice_pitch,
                 void *                  host_ptr,
-                cl_int *                errcode_ret) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+                cl_int *                errcode_ret) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
-extern CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
+extern CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
 clEnqueueMarker(cl_command_queue    command_queue,
-                cl_event *          event) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+                cl_event *          event) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
-extern CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
+extern CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
 clEnqueueWaitForEvents(cl_command_queue  command_queue,
                         cl_uint          num_events,
-                        const cl_event * event_list) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+                        const cl_event * event_list) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
-extern CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
-clEnqueueBarrier(cl_command_queue command_queue) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+extern CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
+clEnqueueBarrier(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
-extern CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
-clUnloadCompiler(void) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+extern CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
+clUnloadCompiler(void) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
-extern CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_1_DEPRECATED void * CL_API_CALL
-clGetExtensionFunctionAddress(const char * func_name) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+extern CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED void * CL_API_CALL
+clGetExtensionFunctionAddress(const char * func_name) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
 /* Deprecated OpenCL 2.0 APIs */
-extern CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_2_DEPRECATED cl_command_queue CL_API_CALL
+extern CL_API_ENTRY CL_API_PREFIX__VERSION_1_2_DEPRECATED cl_command_queue CL_API_CALL
 clCreateCommandQueue(cl_context                     context,
                      cl_device_id                   device,
                      cl_command_queue_properties    properties,
-                     cl_int *                       errcode_ret) CL_EXT_SUFFIX__VERSION_1_2_DEPRECATED;
+                     cl_int *                       errcode_ret) CL_API_SUFFIX__VERSION_1_2_DEPRECATED;
 
-extern CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_2_DEPRECATED cl_sampler CL_API_CALL
+extern CL_API_ENTRY CL_API_PREFIX__VERSION_1_2_DEPRECATED cl_sampler CL_API_CALL
 clCreateSampler(cl_context          context,
                 cl_bool             normalized_coords,
                 cl_addressing_mode  addressing_mode,
                 cl_filter_mode      filter_mode,
-                cl_int *            errcode_ret) CL_EXT_SUFFIX__VERSION_1_2_DEPRECATED;
+                cl_int *            errcode_ret) CL_API_SUFFIX__VERSION_1_2_DEPRECATED;
 
-extern CL_API_ENTRY CL_EXT_PREFIX__VERSION_1_2_DEPRECATED cl_int CL_API_CALL
+extern CL_API_ENTRY CL_API_PREFIX__VERSION_1_2_DEPRECATED cl_int CL_API_CALL
 clEnqueueTask(cl_command_queue  command_queue,
               cl_kernel         kernel,
               cl_uint           num_events_in_wait_list,
               const cl_event *  event_wait_list,
-              cl_event *        event) CL_EXT_SUFFIX__VERSION_1_2_DEPRECATED;
+              cl_event *        event) CL_API_SUFFIX__VERSION_1_2_DEPRECATED;
 
 #ifdef __cplusplus
 }
