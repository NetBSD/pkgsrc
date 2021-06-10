$NetBSD: patch-khronos-headers_CL_cl__ext.h,v 1.1 2021/06/10 05:55:42 nia Exp $

[PATCH] Updated to support latest Khronos headers.

Signed-off-by: Laurent Carlier <lordheavym@gmail.com>

--- khronos-headers/CL/cl_ext.h.orig	2021-03-30 16:10:38.000000000 +0000
+++ khronos-headers/CL/cl_ext.h
@@ -54,9 +54,9 @@ extern "C" {
  * before using.
  */
 #define cl_APPLE_SetMemObjectDestructor 1
-cl_int  CL_API_ENTRY clSetMemObjectDestructorAPPLE(  cl_mem memobj,
+extern CL_API_ENTRY cl_int CL_API_CALL clSetMemObjectDestructorAPPLE(  cl_mem memobj,
                                         void (* pfn_notify)(cl_mem memobj, void * user_data),
-                                        void * user_data)             CL_EXT_SUFFIX__VERSION_1_0;
+                                        void * user_data)             CL_API_SUFFIX__VERSION_1_0;
 
 
 /* Context Logging Functions
@@ -68,22 +68,22 @@ cl_int  CL_API_ENTRY clSetMemObjectDestr
  * clLogMessagesToSystemLog forwards on all log messages to the Apple System Logger
  */
 #define cl_APPLE_ContextLoggingFunctions 1
-extern void CL_API_ENTRY clLogMessagesToSystemLogAPPLE(  const char * errstr,
+extern CL_API_ENTRY void CL_API_CALL clLogMessagesToSystemLogAPPLE(  const char * errstr,
                                             const void * private_info,
                                             size_t       cb,
-                                            void *       user_data)  CL_EXT_SUFFIX__VERSION_1_0;
+                                            void *       user_data)  CL_API_SUFFIX__VERSION_1_0;
 
 /* clLogMessagesToStdout sends all log messages to the file descriptor stdout */
-extern void CL_API_ENTRY clLogMessagesToStdoutAPPLE(   const char * errstr,
+extern CL_API_ENTRY void CL_API_CALL clLogMessagesToStdoutAPPLE(   const char * errstr,
                                           const void * private_info,
                                           size_t       cb,
-                                          void *       user_data)    CL_EXT_SUFFIX__VERSION_1_0;
+                                          void *       user_data)    CL_API_SUFFIX__VERSION_1_0;
 
 /* clLogMessagesToStderr sends all log messages to the file descriptor stderr */
-extern void CL_API_ENTRY clLogMessagesToStderrAPPLE(   const char * errstr,
+extern CL_API_ENTRY void CL_API_CALL clLogMessagesToStderrAPPLE(   const char * errstr,
                                           const void * private_info,
                                           size_t       cb,
-                                          void *       user_data)    CL_EXT_SUFFIX__VERSION_1_0;
+                                          void *       user_data)    CL_API_SUFFIX__VERSION_1_0;
 
 
 /************************
@@ -102,7 +102,7 @@ clIcdGetPlatformIDsKHR(cl_uint          
                        cl_platform_id * platforms,
                        cl_uint *        num_platforms);
 
-typedef CL_API_ENTRY cl_int
+typedef cl_int
 (CL_API_CALL *clIcdGetPlatformIDsKHR_fn)(cl_uint          num_entries,
                                          cl_platform_id * platforms,
                                          cl_uint *        num_platforms);
@@ -129,11 +129,11 @@ clCreateProgramWithILKHR(cl_context   co
                          size_t       length,
                          cl_int *     errcode_ret);
 
-typedef CL_API_ENTRY cl_program
+typedef cl_program
 (CL_API_CALL *clCreateProgramWithILKHR_fn)(cl_context   context,
                                            const void * il,
                                            size_t       length,
-                                           cl_int *     errcode_ret) CL_EXT_SUFFIX__VERSION_1_2;
+                                           cl_int *     errcode_ret) CL_API_SUFFIX__VERSION_1_2;
 
 /* Extension: cl_khr_image2d_from_buffer
  *
@@ -176,10 +176,10 @@ typedef CL_API_ENTRY cl_program
 
 #define cl_khr_terminate_context 1
 extern CL_API_ENTRY cl_int CL_API_CALL
-clTerminateContextKHR(cl_context context) CL_EXT_SUFFIX__VERSION_1_2;
+clTerminateContextKHR(cl_context context) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_int
-(CL_API_CALL *clTerminateContextKHR_fn)(cl_context context) CL_EXT_SUFFIX__VERSION_1_2;
+typedef cl_int
+(CL_API_CALL *clTerminateContextKHR_fn)(cl_context context) CL_API_SUFFIX__VERSION_1_2;
 
 
 /*
@@ -204,13 +204,13 @@ extern CL_API_ENTRY cl_command_queue CL_
 clCreateCommandQueueWithPropertiesKHR(cl_context context,
                                       cl_device_id device,
                                       const cl_queue_properties_khr* properties,
-                                      cl_int* errcode_ret) CL_EXT_SUFFIX__VERSION_1_2;
+                                      cl_int* errcode_ret) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_command_queue
+typedef cl_command_queue
 (CL_API_CALL *clCreateCommandQueueWithPropertiesKHR_fn)(cl_context context,
                                                         cl_device_id device,
                                                         const cl_queue_properties_khr* properties,
-                                                        cl_int* errcode_ret) CL_EXT_SUFFIX__VERSION_1_2;
+                                                        cl_int* errcode_ret) CL_API_SUFFIX__VERSION_1_2;
 
 
 /******************************************
@@ -268,16 +268,16 @@ typedef CL_API_ENTRY cl_command_queue
 #define cl_ext_device_fission   1
 
 extern CL_API_ENTRY cl_int CL_API_CALL
-clReleaseDeviceEXT(cl_device_id device) CL_EXT_SUFFIX__VERSION_1_1;
+clReleaseDeviceEXT(cl_device_id device) CL_API_SUFFIX__VERSION_1_1;
 
-typedef CL_API_ENTRY cl_int
-(CL_API_CALL *clReleaseDeviceEXT_fn)(cl_device_id device) CL_EXT_SUFFIX__VERSION_1_1;
+typedef cl_int
+(CL_API_CALL *clReleaseDeviceEXT_fn)(cl_device_id device) CL_API_SUFFIX__VERSION_1_1;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
-clRetainDeviceEXT(cl_device_id device) CL_EXT_SUFFIX__VERSION_1_1;
+clRetainDeviceEXT(cl_device_id device) CL_API_SUFFIX__VERSION_1_1;
 
-typedef CL_API_ENTRY cl_int
-(CL_API_CALL *clRetainDeviceEXT_fn)(cl_device_id device) CL_EXT_SUFFIX__VERSION_1_1;
+typedef cl_int
+(CL_API_CALL *clRetainDeviceEXT_fn)(cl_device_id device) CL_API_SUFFIX__VERSION_1_1;
 
 typedef cl_ulong  cl_device_partition_property_ext;
 extern CL_API_ENTRY cl_int CL_API_CALL
@@ -285,14 +285,14 @@ clCreateSubDevicesEXT(cl_device_id   in_
                       const cl_device_partition_property_ext * properties,
                       cl_uint        num_entries,
                       cl_device_id * out_devices,
-                      cl_uint *      num_devices) CL_EXT_SUFFIX__VERSION_1_1;
+                      cl_uint *      num_devices) CL_API_SUFFIX__VERSION_1_1;
 
-typedef CL_API_ENTRY cl_int
+typedef cl_int
 (CL_API_CALL * clCreateSubDevicesEXT_fn)(cl_device_id   in_device,
                                          const cl_device_partition_property_ext * properties,
                                          cl_uint        num_entries,
                                          cl_device_id * out_devices,
-                                         cl_uint *      num_devices) CL_EXT_SUFFIX__VERSION_1_1;
+                                         cl_uint *      num_devices) CL_API_SUFFIX__VERSION_1_1;
 
 /* cl_device_partition_property_ext */
 #define CL_DEVICE_PARTITION_EQUALLY_EXT             0x4050
@@ -346,7 +346,7 @@ clEnqueueMigrateMemObjectEXT(cl_command_
                              const cl_event * event_wait_list,
                              cl_event *       event);
 
-typedef CL_API_ENTRY cl_int
+typedef cl_int
 (CL_API_CALL *clEnqueueMigrateMemObjectEXT_fn)(cl_command_queue command_queue,
                                                cl_uint          num_mem_objects,
                                                const cl_mem *   mem_objects,
@@ -490,7 +490,7 @@ clEnqueueAcquireGrallocObjectsIMG(cl_com
                                   const cl_mem *        mem_objects,
                                   cl_uint               num_events_in_wait_list,
                                   const cl_event *      event_wait_list,
-                                  cl_event *            event) CL_EXT_SUFFIX__VERSION_1_2;
+                                  cl_event *            event) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clEnqueueReleaseGrallocObjectsIMG(cl_command_queue      command_queue,
@@ -498,7 +498,7 @@ clEnqueueReleaseGrallocObjectsIMG(cl_com
                                   const cl_mem *        mem_objects,
                                   cl_uint               num_events_in_wait_list,
                                   const cl_event *      event_wait_list,
-                                  cl_event *            event) CL_EXT_SUFFIX__VERSION_1_2;
+                                  cl_event *            event) CL_API_SUFFIX__VERSION_1_2;
 
 /******************************************
  * cl_img_generate_mipmap extension *
@@ -523,7 +523,7 @@ clEnqueueGenerateMipmapIMG(cl_command_qu
                            const size_t              *mip_region,
                            cl_uint                   num_events_in_wait_list,
                            const cl_event            *event_wait_list,
-                           cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;
+                           cl_event *event) CL_API_SUFFIX__VERSION_1_2;
   
 /******************************************
  * cl_img_mem_properties extension *
@@ -564,9 +564,9 @@ clGetKernelSubGroupInfoKHR(cl_kernel    
                            const void * input_value,
                            size_t       param_value_size,
                            void *       param_value,
-                           size_t *     param_value_size_ret) CL_EXT_SUFFIX__VERSION_2_0_DEPRECATED;
+                           size_t *     param_value_size_ret) CL_API_SUFFIX__VERSION_2_0_DEPRECATED;
 
-typedef CL_API_ENTRY cl_int
+typedef cl_int
 (CL_API_CALL * clGetKernelSubGroupInfoKHR_fn)(cl_kernel    in_kernel,
                                               cl_device_id in_device,
                                               cl_kernel_sub_group_info param_name,
@@ -574,7 +574,7 @@ typedef CL_API_ENTRY cl_int
                                               const void * input_value,
                                               size_t       param_value_size,
                                               void *       param_value,
-                                              size_t *     param_value_size_ret) CL_EXT_SUFFIX__VERSION_2_0_DEPRECATED;
+                                              size_t *     param_value_size_ret) CL_API_SUFFIX__VERSION_2_0_DEPRECATED;
 
 
 /*********************************
@@ -694,6 +694,46 @@ typedef struct _cl_name_version_khr
 #define CL_DEVICE_NODE_MASK_KHR     0x106E
 
 
+/***************************************************************
+* cl_khr_pci_bus_info
+***************************************************************/
+#define cl_khr_pci_bus_info 1
+
+typedef struct _cl_device_pci_bus_info_khr {
+    cl_uint pci_domain;
+    cl_uint pci_bus;
+    cl_uint pci_device;
+    cl_uint pci_function;
+} cl_device_pci_bus_info_khr;
+
+/* cl_device_info */
+#define CL_DEVICE_PCI_BUS_INFO_KHR                          0x410F
+
+
+/***************************************************************
+* cl_khr_suggested_local_work_size
+***************************************************************/
+#define cl_khr_suggested_local_work_size 1
+
+extern CL_API_ENTRY cl_int CL_API_CALL
+clGetKernelSuggestedLocalWorkSizeKHR(
+    cl_command_queue command_queue,
+    cl_kernel kernel,
+    cl_uint work_dim,
+    const size_t* global_work_offset,
+    const size_t* global_work_size,
+    size_t* suggested_local_work_size) CL_API_SUFFIX__VERSION_3_0;
+
+typedef cl_int (CL_API_CALL *
+clGetKernelSuggestedLocalWorkSizeKHR_fn)(
+    cl_command_queue command_queue,
+    cl_kernel kernel,
+    cl_uint work_dim,
+    const size_t* global_work_offset,
+    const size_t* global_work_size,
+    size_t* suggested_local_work_size) CL_API_SUFFIX__VERSION_3_0;
+
+
 /**********************************
  * cl_arm_import_memory extension *
  **********************************/
@@ -719,6 +759,12 @@ typedef intptr_t cl_import_properties_ar
 /* Data consistency with host property */
 #define CL_IMPORT_DMA_BUF_DATA_CONSISTENCY_WITH_HOST_ARM 0x41E3
 
+/* Index of plane in a multiplanar hardware buffer */
+#define CL_IMPORT_ANDROID_HARDWARE_BUFFER_PLANE_INDEX_ARM 0x41EF
+
+/* Index of layer in a multilayer hardware buffer */
+#define CL_IMPORT_ANDROID_HARDWARE_BUFFER_LAYER_INDEX_ARM 0x41F0
+
 /* Import memory size value to indicate a size for the whole buffer */
 #define CL_IMPORT_MEMORY_WHOLE_ALLOCATION_ARM SIZE_MAX
 
@@ -744,7 +790,7 @@ clImportMemoryARM( cl_context context,
                    const cl_import_properties_arm *properties,
                    void *memory,
                    size_t size,
-                   cl_int *errcode_ret) CL_EXT_SUFFIX__VERSION_1_0;
+                   cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
 
 /******************************************
@@ -787,11 +833,11 @@ extern CL_API_ENTRY void * CL_API_CALL
 clSVMAllocARM(cl_context       context,
               cl_svm_mem_flags_arm flags,
               size_t           size,
-              cl_uint          alignment) CL_EXT_SUFFIX__VERSION_1_2;
+              cl_uint          alignment) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY void CL_API_CALL
 clSVMFreeARM(cl_context        context,
-             void *            svm_pointer) CL_EXT_SUFFIX__VERSION_1_2;
+             void *            svm_pointer) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clEnqueueSVMFreeARM(cl_command_queue  command_queue,
@@ -804,7 +850,7 @@ clEnqueueSVMFreeARM(cl_command_queue  co
                     void *            user_data,
                     cl_uint           num_events_in_wait_list,
                     const cl_event *  event_wait_list,
-                    cl_event *        event) CL_EXT_SUFFIX__VERSION_1_2;
+                    cl_event *        event) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clEnqueueSVMMemcpyARM(cl_command_queue  command_queue,
@@ -814,7 +860,7 @@ clEnqueueSVMMemcpyARM(cl_command_queue  
                       size_t            size,
                       cl_uint           num_events_in_wait_list,
                       const cl_event *  event_wait_list,
-                      cl_event *        event) CL_EXT_SUFFIX__VERSION_1_2;
+                      cl_event *        event) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clEnqueueSVMMemFillARM(cl_command_queue  command_queue,
@@ -824,7 +870,7 @@ clEnqueueSVMMemFillARM(cl_command_queue 
                        size_t            size,
                        cl_uint           num_events_in_wait_list,
                        const cl_event *  event_wait_list,
-                       cl_event *        event) CL_EXT_SUFFIX__VERSION_1_2;
+                       cl_event *        event) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clEnqueueSVMMapARM(cl_command_queue  command_queue,
@@ -834,25 +880,25 @@ clEnqueueSVMMapARM(cl_command_queue  com
                    size_t            size,
                    cl_uint           num_events_in_wait_list,
                    const cl_event *  event_wait_list,
-                   cl_event *        event) CL_EXT_SUFFIX__VERSION_1_2;
+                   cl_event *        event) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clEnqueueSVMUnmapARM(cl_command_queue  command_queue,
                      void *            svm_ptr,
                      cl_uint           num_events_in_wait_list,
                      const cl_event *  event_wait_list,
-                     cl_event *        event) CL_EXT_SUFFIX__VERSION_1_2;
+                     cl_event *        event) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clSetKernelArgSVMPointerARM(cl_kernel    kernel,
                             cl_uint      arg_index,
-                            const void * arg_value) CL_EXT_SUFFIX__VERSION_1_2;
+                            const void * arg_value) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clSetKernelExecInfoARM(cl_kernel            kernel,
                        cl_kernel_exec_info_arm  param_name,
                        size_t               param_value_size,
-                       const void *         param_value) CL_EXT_SUFFIX__VERSION_1_2;
+                       const void *         param_value) CL_API_SUFFIX__VERSION_1_2;
 
 /********************************
  * cl_arm_get_core_id extension *
@@ -1060,14 +1106,14 @@ clCreateAcceleratorINTEL(
     cl_accelerator_type_intel    accelerator_type,
     size_t                       descriptor_size,
     const void*                  descriptor,
-    cl_int*                      errcode_ret) CL_EXT_SUFFIX__VERSION_1_2;
+    cl_int*                      errcode_ret) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_accelerator_intel (CL_API_CALL *clCreateAcceleratorINTEL_fn)(
+typedef cl_accelerator_intel (CL_API_CALL *clCreateAcceleratorINTEL_fn)(
     cl_context                   context,
     cl_accelerator_type_intel    accelerator_type,
     size_t                       descriptor_size,
     const void*                  descriptor,
-    cl_int*                      errcode_ret) CL_EXT_SUFFIX__VERSION_1_2;
+    cl_int*                      errcode_ret) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clGetAcceleratorInfoINTEL(
@@ -1075,28 +1121,28 @@ clGetAcceleratorInfoINTEL(
     cl_accelerator_info_intel    param_name,
     size_t                       param_value_size,
     void*                        param_value,
-    size_t*                      param_value_size_ret) CL_EXT_SUFFIX__VERSION_1_2;
+    size_t*                      param_value_size_ret) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetAcceleratorInfoINTEL_fn)(
+typedef cl_int (CL_API_CALL *clGetAcceleratorInfoINTEL_fn)(
     cl_accelerator_intel         accelerator,
     cl_accelerator_info_intel    param_name,
     size_t                       param_value_size,
     void*                        param_value,
-    size_t*                      param_value_size_ret) CL_EXT_SUFFIX__VERSION_1_2;
+    size_t*                      param_value_size_ret) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clRetainAcceleratorINTEL(
-    cl_accelerator_intel         accelerator) CL_EXT_SUFFIX__VERSION_1_2;
+    cl_accelerator_intel         accelerator) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clRetainAcceleratorINTEL_fn)(
-    cl_accelerator_intel         accelerator) CL_EXT_SUFFIX__VERSION_1_2;
+typedef cl_int (CL_API_CALL *clRetainAcceleratorINTEL_fn)(
+    cl_accelerator_intel         accelerator) CL_API_SUFFIX__VERSION_1_2;
 
 extern CL_API_ENTRY cl_int CL_API_CALL
 clReleaseAcceleratorINTEL(
-    cl_accelerator_intel         accelerator) CL_EXT_SUFFIX__VERSION_1_2;
+    cl_accelerator_intel         accelerator) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *clReleaseAcceleratorINTEL_fn)(
-    cl_accelerator_intel         accelerator) CL_EXT_SUFFIX__VERSION_1_2;
+typedef cl_int (CL_API_CALL *clReleaseAcceleratorINTEL_fn)(
+    cl_accelerator_intel         accelerator) CL_API_SUFFIX__VERSION_1_2;
 
 /******************************************
 * cl_intel_simultaneous_sharing extension *
@@ -1368,7 +1414,7 @@ clHostMemAllocINTEL(
             cl_uint alignment,
             cl_int* errcode_ret);
 
-typedef CL_API_ENTRY void* (CL_API_CALL *
+typedef void* (CL_API_CALL *
 clHostMemAllocINTEL_fn)(
             cl_context context,
             const cl_mem_properties_intel* properties,
@@ -1385,7 +1431,7 @@ clDeviceMemAllocINTEL(
             cl_uint alignment,
             cl_int* errcode_ret);
 
-typedef CL_API_ENTRY void* (CL_API_CALL *
+typedef void* (CL_API_CALL *
 clDeviceMemAllocINTEL_fn)(
             cl_context context,
             cl_device_id device,
@@ -1403,7 +1449,7 @@ clSharedMemAllocINTEL(
             cl_uint alignment,
             cl_int* errcode_ret);
 
-typedef CL_API_ENTRY void* (CL_API_CALL *
+typedef void* (CL_API_CALL *
 clSharedMemAllocINTEL_fn)(
             cl_context context,
             cl_device_id device,
@@ -1417,7 +1463,7 @@ clMemFreeINTEL(
             cl_context context,
             void* ptr);
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *
+typedef cl_int (CL_API_CALL *
 clMemFreeINTEL_fn)(
             cl_context context,
             void* ptr);
@@ -1427,7 +1473,7 @@ clMemBlockingFreeINTEL(
             cl_context context,
             void* ptr);
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *
+typedef cl_int (CL_API_CALL *
 clMemBlockingFreeINTEL_fn)(
             cl_context context,
             void* ptr);
@@ -1441,7 +1487,7 @@ clGetMemAllocInfoINTEL(
             void* param_value,
             size_t* param_value_size_ret);
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *
+typedef cl_int (CL_API_CALL *
 clGetMemAllocInfoINTEL_fn)(
             cl_context context,
             const void* ptr,
@@ -1456,7 +1502,7 @@ clSetKernelArgMemPointerINTEL(
             cl_uint arg_index,
             const void* arg_value);
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *
+typedef cl_int (CL_API_CALL *
 clSetKernelArgMemPointerINTEL_fn)(
             cl_kernel kernel,
             cl_uint arg_index,
@@ -1472,7 +1518,7 @@ clEnqueueMemsetINTEL(       /* Deprecate
             const cl_event* event_wait_list,
             cl_event* event);
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *
+typedef cl_int (CL_API_CALL *
 clEnqueueMemsetINTEL_fn)(   /* Deprecated */
             cl_command_queue command_queue,
             void* dst_ptr,
@@ -1493,7 +1539,7 @@ clEnqueueMemFillINTEL(
             const cl_event* event_wait_list,
             cl_event* event);
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *
+typedef cl_int (CL_API_CALL *
 clEnqueueMemFillINTEL_fn)(
             cl_command_queue command_queue,
             void* dst_ptr,
@@ -1515,7 +1561,7 @@ clEnqueueMemcpyINTEL(
             const cl_event* event_wait_list,
             cl_event* event);
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *
+typedef cl_int (CL_API_CALL *
 clEnqueueMemcpyINTEL_fn)(
             cl_command_queue command_queue,
             cl_bool blocking,
@@ -1541,7 +1587,7 @@ clEnqueueMigrateMemINTEL(
             const cl_event* event_wait_list,
             cl_event* event);
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *
+typedef cl_int (CL_API_CALL *
 clEnqueueMigrateMemINTEL_fn)(
             cl_command_queue command_queue,
             const void* ptr,
@@ -1563,7 +1609,7 @@ clEnqueueMemAdviseINTEL(
             const cl_event* event_wait_list,
             cl_event* event);
 
-typedef CL_API_ENTRY cl_int (CL_API_CALL *
+typedef cl_int (CL_API_CALL *
 clEnqueueMemAdviseINTEL_fn)(
             cl_command_queue command_queue,
             const void* ptr,
@@ -1586,16 +1632,16 @@ clCreateBufferWithPropertiesINTEL(
     cl_mem_flags flags,
     size_t       size,
     void *       host_ptr,
-    cl_int *     errcode_ret) CL_EXT_SUFFIX__VERSION_1_0;
+    cl_int *     errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_mem (CL_API_CALL *
+typedef cl_mem (CL_API_CALL *
 clCreateBufferWithPropertiesINTEL_fn)(
     cl_context   context,
     const cl_mem_properties_intel* properties,
     cl_mem_flags flags,
     size_t       size,
     void *       host_ptr,
-    cl_int *     errcode_ret) CL_EXT_SUFFIX__VERSION_1_0;
+    cl_int *     errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
 /******************************************
 * cl_intel_mem_channel_property extension *
@@ -1612,6 +1658,48 @@ clCreateBufferWithPropertiesINTEL_fn)(
 /* cl_mem_flags */
 #define CL_MEM_FORCE_HOST_MEMORY_INTEL                      (1 << 20)
 
+/***************************************************************
+* cl_intel_command_queue_families
+***************************************************************/
+#define cl_intel_command_queue_families 1
+
+typedef cl_bitfield         cl_command_queue_capabilities_intel;
+
+#define CL_QUEUE_FAMILY_MAX_NAME_SIZE_INTEL                 64
+
+typedef struct _cl_queue_family_properties_intel {
+    cl_command_queue_properties properties;
+    cl_command_queue_capabilities_intel capabilities;
+    cl_uint count;
+    char name[CL_QUEUE_FAMILY_MAX_NAME_SIZE_INTEL];
+} cl_queue_family_properties_intel;
+
+/* cl_device_info */
+#define CL_DEVICE_QUEUE_FAMILY_PROPERTIES_INTEL             0x418B
+
+/* cl_queue_properties */
+#define CL_QUEUE_FAMILY_INTEL                               0x418C
+#define CL_QUEUE_INDEX_INTEL                                0x418D
+
+/* cl_command_queue_capabilities_intel */
+#define CL_QUEUE_DEFAULT_CAPABILITIES_INTEL                 0
+#define CL_QUEUE_CAPABILITY_CREATE_SINGLE_QUEUE_EVENTS_INTEL (1 << 0)
+#define CL_QUEUE_CAPABILITY_CREATE_CROSS_QUEUE_EVENTS_INTEL (1 << 1)
+#define CL_QUEUE_CAPABILITY_SINGLE_QUEUE_EVENT_WAIT_LIST_INTEL (1 << 2)
+#define CL_QUEUE_CAPABILITY_CROSS_QUEUE_EVENT_WAIT_LIST_INTEL (1 << 3)
+#define CL_QUEUE_CAPABILITY_TRANSFER_BUFFER_INTEL           (1 << 8)
+#define CL_QUEUE_CAPABILITY_TRANSFER_BUFFER_RECT_INTEL      (1 << 9)
+#define CL_QUEUE_CAPABILITY_MAP_BUFFER_INTEL                (1 << 10)
+#define CL_QUEUE_CAPABILITY_FILL_BUFFER_INTEL               (1 << 11)
+#define CL_QUEUE_CAPABILITY_TRANSFER_IMAGE_INTEL            (1 << 12)
+#define CL_QUEUE_CAPABILITY_MAP_IMAGE_INTEL                 (1 << 13)
+#define CL_QUEUE_CAPABILITY_FILL_IMAGE_INTEL                (1 << 14)
+#define CL_QUEUE_CAPABILITY_TRANSFER_BUFFER_IMAGE_INTEL     (1 << 15)
+#define CL_QUEUE_CAPABILITY_TRANSFER_IMAGE_BUFFER_INTEL     (1 << 16)
+#define CL_QUEUE_CAPABILITY_MARKER_INTEL                    (1 << 24)
+#define CL_QUEUE_CAPABILITY_BARRIER_INTEL                   (1 << 25)
+#define CL_QUEUE_CAPABILITY_KERNEL_INTEL                    (1 << 26)
+
 #ifdef __cplusplus
 }
 #endif
