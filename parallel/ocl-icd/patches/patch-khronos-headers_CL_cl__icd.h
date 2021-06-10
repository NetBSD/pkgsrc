$NetBSD: patch-khronos-headers_CL_cl__icd.h,v 1.1 2021/06/10 05:55:42 nia Exp $

[PATCH] Updated to support latest Khronos headers.

Signed-off-by: Laurent Carlier <lordheavym@gmail.com>

--- khronos-headers/CL/cl_icd.h.orig	2021-03-30 16:10:38.000000000 +0000
+++ khronos-headers/CL/cl_icd.h
@@ -41,35 +41,35 @@ extern "C" {
 /* API function pointer definitions */
 
 // Platform APIs
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetPlatformIDs)(
+typedef cl_int(CL_API_CALL *cl_api_clGetPlatformIDs)(
     cl_uint num_entries, cl_platform_id *platforms,
     cl_uint *num_platforms) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetPlatformInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetPlatformInfo)(
     cl_platform_id platform, cl_platform_info param_name,
     size_t param_value_size, void *param_value,
     size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
 // Device APIs
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetDeviceIDs)(
+typedef cl_int(CL_API_CALL *cl_api_clGetDeviceIDs)(
     cl_platform_id platform, cl_device_type device_type, cl_uint num_entries,
     cl_device_id *devices, cl_uint *num_devices) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetDeviceInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetDeviceInfo)(
     cl_device_id device, cl_device_info param_name, size_t param_value_size,
     void *param_value, size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
 #ifdef CL_VERSION_1_2
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clCreateSubDevices)(
+typedef cl_int(CL_API_CALL *cl_api_clCreateSubDevices)(
     cl_device_id in_device,
     const cl_device_partition_property *partition_properties,
     cl_uint num_entries, cl_device_id *out_devices, cl_uint *num_devices);
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clRetainDevice)(
+typedef cl_int(CL_API_CALL *cl_api_clRetainDevice)(
     cl_device_id device) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clReleaseDevice)(
+typedef cl_int(CL_API_CALL *cl_api_clReleaseDevice)(
     cl_device_id device) CL_API_SUFFIX__VERSION_1_2;
 
 #else
@@ -81,36 +81,36 @@ typedef void *cl_api_clReleaseDevice;
 #endif
 
 // Context APIs
-typedef CL_API_ENTRY cl_context(CL_API_CALL *cl_api_clCreateContext)(
+typedef cl_context(CL_API_CALL *cl_api_clCreateContext)(
     const cl_context_properties *properties, cl_uint num_devices,
     const cl_device_id *devices,
     void(CL_CALLBACK *pfn_notify)(const char *, const void *, size_t, void *),
     void *user_data, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_context(CL_API_CALL *cl_api_clCreateContextFromType)(
+typedef cl_context(CL_API_CALL *cl_api_clCreateContextFromType)(
     const cl_context_properties *properties, cl_device_type device_type,
     void(CL_CALLBACK *pfn_notify)(const char *, const void *, size_t, void *),
     void *user_data, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clRetainContext)(
+typedef cl_int(CL_API_CALL *cl_api_clRetainContext)(
     cl_context context) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clReleaseContext)(
+typedef cl_int(CL_API_CALL *cl_api_clReleaseContext)(
     cl_context context) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetContextInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetContextInfo)(
     cl_context context, cl_context_info param_name, size_t param_value_size,
     void *param_value, size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
 // Command Queue APIs
-typedef CL_API_ENTRY cl_command_queue(CL_API_CALL *cl_api_clCreateCommandQueue)(
+typedef cl_command_queue(CL_API_CALL *cl_api_clCreateCommandQueue)(
     cl_context context, cl_device_id device,
     cl_command_queue_properties properties,
     cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
 #ifdef CL_VERSION_2_0
 
-typedef CL_API_ENTRY
+typedef
 cl_command_queue(CL_API_CALL *cl_api_clCreateCommandQueueWithProperties)(
     cl_context /* context */, cl_device_id /* device */,
     const cl_queue_properties * /* properties */,
@@ -122,25 +122,25 @@ typedef void *cl_api_clCreateCommandQueu
 
 #endif
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clRetainCommandQueue)(
+typedef cl_int(CL_API_CALL *cl_api_clRetainCommandQueue)(
     cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clReleaseCommandQueue)(
+typedef cl_int(CL_API_CALL *cl_api_clReleaseCommandQueue)(
     cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetCommandQueueInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetCommandQueueInfo)(
     cl_command_queue command_queue, cl_command_queue_info param_name,
     size_t param_value_size, void *param_value,
     size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
 // Memory Object APIs
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateBuffer)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateBuffer)(
     cl_context context, cl_mem_flags flags, size_t size, void *host_ptr,
     cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
 #ifdef CL_VERSION_1_2
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateImage)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateImage)(
     cl_context context, cl_mem_flags flags, const cl_image_format *image_format,
     const cl_image_desc *image_desc, void *host_ptr,
     cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_2;
@@ -153,17 +153,17 @@ typedef void *cl_api_clCreateImage;
 
 #ifdef CL_VERSION_3_0
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateBufferWithProperties)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateBufferWithProperties)(
     cl_context context, const cl_mem_properties *properties, cl_mem_flags flags,
     size_t size, void *host_ptr,
     cl_int *errcode_ret) CL_API_SUFFIX__VERSION_3_0;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateImageWithProperties)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateImageWithProperties)(
     cl_context context, const cl_mem_properties *properties, cl_mem_flags flags,
     const cl_image_format *image_format, const cl_image_desc *image_desc,
     void *host_ptr, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_3_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL* cl_api_clSetContextDestructorCallback)(
+typedef cl_int(CL_API_CALL* cl_api_clSetContextDestructorCallback)(
     cl_context context,
     void(CL_CALLBACK* pfn_notify)(cl_context context, void* user_data),
     void* user_data) CL_API_SUFFIX__VERSION_3_0;
@@ -176,43 +176,43 @@ typedef void *cl_api_clSetContextDestruc
 
 #endif
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clRetainMemObject)(
+typedef cl_int(CL_API_CALL *cl_api_clRetainMemObject)(
     cl_mem memobj) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clReleaseMemObject)(
+typedef cl_int(CL_API_CALL *cl_api_clReleaseMemObject)(
     cl_mem memobj) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetSupportedImageFormats)(
+typedef cl_int(CL_API_CALL *cl_api_clGetSupportedImageFormats)(
     cl_context context, cl_mem_flags flags, cl_mem_object_type image_type,
     cl_uint num_entries, cl_image_format *image_formats,
     cl_uint *num_image_formats) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetMemObjectInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetMemObjectInfo)(
     cl_mem memobj, cl_mem_info param_name, size_t param_value_size,
     void *param_value, size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetImageInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetImageInfo)(
     cl_mem image, cl_image_info param_name, size_t param_value_size,
     void *param_value, size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
 #ifdef CL_VERSION_2_0
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreatePipe)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreatePipe)(
     cl_context /* context */, cl_mem_flags /* flags */,
     cl_uint /* pipe_packet_size */, cl_uint /* pipe_max_packets */,
     const cl_pipe_properties * /* properties */,
     cl_int * /* errcode_ret */) CL_API_SUFFIX__VERSION_2_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetPipeInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetPipeInfo)(
     cl_mem /* pipe */, cl_pipe_info /* param_name */,
     size_t /* param_value_size */, void * /* param_value */,
     size_t * /* param_value_size_ret */) CL_API_SUFFIX__VERSION_2_0;
 
-typedef CL_API_ENTRY void *(CL_API_CALL *cl_api_clSVMAlloc)(
+typedef void *(CL_API_CALL *cl_api_clSVMAlloc)(
     cl_context /* context */, cl_svm_mem_flags /* flags */, size_t /* size */,
     unsigned int /* alignment */)CL_API_SUFFIX__VERSION_2_0;
 
-typedef CL_API_ENTRY void(CL_API_CALL *cl_api_clSVMFree)(
+typedef void(CL_API_CALL *cl_api_clSVMFree)(
     cl_context /* context */,
     void * /* svm_pointer */) CL_API_SUFFIX__VERSION_2_0;
 
@@ -226,24 +226,24 @@ typedef void *cl_api_clSVMFree;
 #endif
 
 // Sampler APIs
-typedef CL_API_ENTRY cl_sampler(CL_API_CALL *cl_api_clCreateSampler)(
+typedef cl_sampler(CL_API_CALL *cl_api_clCreateSampler)(
     cl_context context, cl_bool normalized_coords,
     cl_addressing_mode addressing_mode, cl_filter_mode filter_mode,
     cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clRetainSampler)(
+typedef cl_int(CL_API_CALL *cl_api_clRetainSampler)(
     cl_sampler sampler) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clReleaseSampler)(
+typedef cl_int(CL_API_CALL *cl_api_clReleaseSampler)(
     cl_sampler sampler) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetSamplerInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetSamplerInfo)(
     cl_sampler sampler, cl_sampler_info param_name, size_t param_value_size,
     void *param_value, size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
 #ifdef CL_VERSION_2_0
 
-typedef CL_API_ENTRY
+typedef
 cl_sampler(CL_API_CALL *cl_api_clCreateSamplerWithProperties)(
     cl_context /* context */,
     const cl_sampler_properties * /* sampler_properties */,
@@ -256,18 +256,18 @@ typedef void *cl_api_clCreateSamplerWith
 #endif
 
 // Program Object APIs
-typedef CL_API_ENTRY cl_program(CL_API_CALL *cl_api_clCreateProgramWithSource)(
+typedef cl_program(CL_API_CALL *cl_api_clCreateProgramWithSource)(
     cl_context context, cl_uint count, const char **strings,
     const size_t *lengths, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_program(CL_API_CALL *cl_api_clCreateProgramWithBinary)(
+typedef cl_program(CL_API_CALL *cl_api_clCreateProgramWithBinary)(
     cl_context context, cl_uint num_devices, const cl_device_id *device_list,
     const size_t *lengths, const unsigned char **binaries,
     cl_int *binary_status, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
 #ifdef CL_VERSION_1_2
 
-typedef CL_API_ENTRY
+typedef
 cl_program(CL_API_CALL *cl_api_clCreateProgramWithBuiltInKernels)(
     cl_context context, cl_uint num_devices, const cl_device_id *device_list,
     const char *kernel_names, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_2;
@@ -278,13 +278,13 @@ typedef void *cl_api_clCreateProgramWith
 
 #endif
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clRetainProgram)(
+typedef cl_int(CL_API_CALL *cl_api_clRetainProgram)(
     cl_program program) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clReleaseProgram)(
+typedef cl_int(CL_API_CALL *cl_api_clReleaseProgram)(
     cl_program program) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clBuildProgram)(
+typedef cl_int(CL_API_CALL *cl_api_clBuildProgram)(
     cl_program program, cl_uint num_devices, const cl_device_id *device_list,
     const char *options,
     void(CL_CALLBACK *pfn_notify)(cl_program program, void *user_data),
@@ -292,14 +292,14 @@ typedef CL_API_ENTRY cl_int(CL_API_CALL 
 
 #ifdef CL_VERSION_1_2
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clCompileProgram)(
+typedef cl_int(CL_API_CALL *cl_api_clCompileProgram)(
     cl_program program, cl_uint num_devices, const cl_device_id *device_list,
     const char *options, cl_uint num_input_headers,
     const cl_program *input_headers, const char **header_include_names,
     void(CL_CALLBACK *pfn_notify)(cl_program program, void *user_data),
     void *user_data) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_program(CL_API_CALL *cl_api_clLinkProgram)(
+typedef cl_program(CL_API_CALL *cl_api_clLinkProgram)(
     cl_context context, cl_uint num_devices, const cl_device_id *device_list,
     const char *options, cl_uint num_input_programs,
     const cl_program *input_programs,
@@ -315,12 +315,12 @@ typedef void *cl_api_clLinkProgram;
 
 #ifdef CL_VERSION_2_2
 
-typedef CL_API_ENTRY
+typedef
 cl_int(CL_API_CALL *cl_api_clSetProgramSpecializationConstant)(
     cl_program program, cl_uint spec_id, size_t spec_size,
     const void *spec_value) CL_API_SUFFIX__VERSION_2_2;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clSetProgramReleaseCallback)(
+typedef cl_int(CL_API_CALL *cl_api_clSetProgramReleaseCallback)(
     cl_program program,
     void(CL_CALLBACK *pfn_notify)(cl_program program, void *user_data),
     void *user_data) CL_API_SUFFIX__VERSION_2_2;
@@ -334,7 +334,7 @@ typedef void *cl_api_clSetProgramRelease
 
 #ifdef CL_VERSION_1_2
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clUnloadPlatformCompiler)(
+typedef cl_int(CL_API_CALL *cl_api_clUnloadPlatformCompiler)(
     cl_platform_id platform) CL_API_SUFFIX__VERSION_1_2;
 
 #else
@@ -343,41 +343,41 @@ typedef void *cl_api_clUnloadPlatformCom
 
 #endif
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetProgramInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetProgramInfo)(
     cl_program program, cl_program_info param_name, size_t param_value_size,
     void *param_value, size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetProgramBuildInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetProgramBuildInfo)(
     cl_program program, cl_device_id device, cl_program_build_info param_name,
     size_t param_value_size, void *param_value,
     size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
 // Kernel Object APIs
-typedef CL_API_ENTRY cl_kernel(CL_API_CALL *cl_api_clCreateKernel)(
+typedef cl_kernel(CL_API_CALL *cl_api_clCreateKernel)(
     cl_program program, const char *kernel_name,
     cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clCreateKernelsInProgram)(
+typedef cl_int(CL_API_CALL *cl_api_clCreateKernelsInProgram)(
     cl_program program, cl_uint num_kernels, cl_kernel *kernels,
     cl_uint *num_kernels_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clRetainKernel)(
+typedef cl_int(CL_API_CALL *cl_api_clRetainKernel)(
     cl_kernel kernel) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clReleaseKernel)(
+typedef cl_int(CL_API_CALL *cl_api_clReleaseKernel)(
     cl_kernel kernel) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clSetKernelArg)(
+typedef cl_int(CL_API_CALL *cl_api_clSetKernelArg)(
     cl_kernel kernel, cl_uint arg_index, size_t arg_size,
     const void *arg_value) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetKernelInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetKernelInfo)(
     cl_kernel kernel, cl_kernel_info param_name, size_t param_value_size,
     void *param_value, size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
 #ifdef CL_VERSION_1_2
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetKernelArgInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetKernelArgInfo)(
     cl_kernel kernel, cl_uint arg_indx, cl_kernel_arg_info param_name,
     size_t param_value_size, void *param_value,
     size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_2;
@@ -388,28 +388,28 @@ typedef void *cl_api_clGetKernelArgInfo;
 
 #endif
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetKernelWorkGroupInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetKernelWorkGroupInfo)(
     cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info param_name,
     size_t param_value_size, void *param_value,
     size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
 #ifdef CL_VERSION_2_0
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clSetKernelArgSVMPointer)(
+typedef cl_int(CL_API_CALL *cl_api_clSetKernelArgSVMPointer)(
     cl_kernel /* kernel */, cl_uint /* arg_index */,
     const void * /* arg_value */) CL_API_SUFFIX__VERSION_2_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clSetKernelExecInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clSetKernelExecInfo)(
     cl_kernel /* kernel */, cl_kernel_exec_info /* param_name */,
     size_t /* param_value_size */,
     const void * /* param_value */) CL_API_SUFFIX__VERSION_2_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetKernelSubGroupInfoKHR)(
+typedef cl_int(CL_API_CALL *cl_api_clGetKernelSubGroupInfoKHR)(
     cl_kernel /* in_kernel */, cl_device_id /*in_device*/,
     cl_kernel_sub_group_info /* param_name */, size_t /*input_value_size*/,
     const void * /*input_value*/, size_t /*param_value_size*/,
     void * /*param_value*/,
-    size_t * /*param_value_size_ret*/) CL_EXT_SUFFIX__VERSION_2_0;
+    size_t * /*param_value_size_ret*/) CL_API_SUFFIX__VERSION_2_0;
 
 #else
 
@@ -420,33 +420,33 @@ typedef void *cl_api_clGetKernelSubGroup
 #endif
 
 // Event Object APIs
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clWaitForEvents)(
+typedef cl_int(CL_API_CALL *cl_api_clWaitForEvents)(
     cl_uint num_events, const cl_event *event_list) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetEventInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetEventInfo)(
     cl_event event, cl_event_info param_name, size_t param_value_size,
     void *param_value, size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clRetainEvent)(cl_event event)
+typedef cl_int(CL_API_CALL *cl_api_clRetainEvent)(cl_event event)
     CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clReleaseEvent)(cl_event event)
+typedef cl_int(CL_API_CALL *cl_api_clReleaseEvent)(cl_event event)
     CL_API_SUFFIX__VERSION_1_0;
 
 // Profiling APIs
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetEventProfilingInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetEventProfilingInfo)(
     cl_event event, cl_profiling_info param_name, size_t param_value_size,
     void *param_value, size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
 // Flush and Finish APIs
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clFlush)(
+typedef cl_int(CL_API_CALL *cl_api_clFlush)(
     cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clFinish)(
+typedef cl_int(CL_API_CALL *cl_api_clFinish)(
     cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0;
 
 // Enqueued Commands APIs
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueReadBuffer)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueReadBuffer)(
     cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read,
     size_t offset, size_t cb, void *ptr, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list,
@@ -454,7 +454,7 @@ typedef CL_API_ENTRY cl_int(CL_API_CALL 
 
 #ifdef CL_VERSION_1_1
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueReadBufferRect)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueReadBufferRect)(
     cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read,
     const size_t *buffer_origin, const size_t *host_origin,
     const size_t *region, size_t buffer_row_pitch, size_t buffer_slice_pitch,
@@ -468,7 +468,7 @@ typedef void *cl_api_clEnqueueReadBuffer
 
 #endif
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueWriteBuffer)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueWriteBuffer)(
     cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write,
     size_t offset, size_t cb, const void *ptr, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list,
@@ -476,7 +476,7 @@ typedef CL_API_ENTRY cl_int(CL_API_CALL 
 
 #ifdef CL_VERSION_1_1
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueWriteBufferRect)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueWriteBufferRect)(
     cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read,
     const size_t *buffer_origin, const size_t *host_origin,
     const size_t *region, size_t buffer_row_pitch, size_t buffer_slice_pitch,
@@ -492,7 +492,7 @@ typedef void *cl_api_clEnqueueWriteBuffe
 
 #ifdef CL_VERSION_1_2
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueFillBuffer)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueFillBuffer)(
     cl_command_queue command_queue, cl_mem buffer, const void *pattern,
     size_t pattern_size, size_t offset, size_t cb,
     cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
@@ -504,7 +504,7 @@ typedef void *cl_api_clEnqueueFillBuffer
 
 #endif
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueCopyBuffer)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueCopyBuffer)(
     cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer,
     size_t src_offset, size_t dst_offset, size_t cb,
     cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
@@ -512,7 +512,7 @@ typedef CL_API_ENTRY cl_int(CL_API_CALL 
 
 #ifdef CL_VERSION_1_1
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueCopyBufferRect)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueCopyBufferRect)(
     cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer,
     const size_t *src_origin, const size_t *dst_origin, const size_t *region,
     size_t src_row_pitch, size_t src_slice_pitch, size_t dst_row_pitch,
@@ -526,14 +526,14 @@ typedef void *cl_api_clEnqueueCopyBuffer
 
 #endif
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueReadImage)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueReadImage)(
     cl_command_queue command_queue, cl_mem image, cl_bool blocking_read,
     const size_t *origin, const size_t *region, size_t row_pitch,
     size_t slice_pitch, void *ptr, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueWriteImage)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueWriteImage)(
     cl_command_queue command_queue, cl_mem image, cl_bool blocking_write,
     const size_t *origin, const size_t *region, size_t input_row_pitch,
     size_t input_slice_pitch, const void *ptr, cl_uint num_events_in_wait_list,
@@ -542,7 +542,7 @@ typedef CL_API_ENTRY cl_int(CL_API_CALL 
 
 #ifdef CL_VERSION_1_2
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueFillImage)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueFillImage)(
     cl_command_queue command_queue, cl_mem image, const void *fill_color,
     const size_t origin[3], const size_t region[3],
     cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
@@ -554,45 +554,45 @@ typedef void *cl_api_clEnqueueFillImage;
 
 #endif
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueCopyImage)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueCopyImage)(
     cl_command_queue command_queue, cl_mem src_image, cl_mem dst_image,
     const size_t *src_origin, const size_t *dst_origin, const size_t *region,
     cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueCopyImageToBuffer)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueCopyImageToBuffer)(
     cl_command_queue command_queue, cl_mem src_image, cl_mem dst_buffer,
     const size_t *src_origin, const size_t *region, size_t dst_offset,
     cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueCopyBufferToImage)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueCopyBufferToImage)(
     cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_image,
     size_t src_offset, const size_t *dst_origin, const size_t *region,
     cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY void *(CL_API_CALL *cl_api_clEnqueueMapBuffer)(
+typedef void *(CL_API_CALL *cl_api_clEnqueueMapBuffer)(
     cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_map,
     cl_map_flags map_flags, size_t offset, size_t cb,
     cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
     cl_event *event, cl_int *errcode_ret)CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY void *(CL_API_CALL *cl_api_clEnqueueMapImage)(
+typedef void *(CL_API_CALL *cl_api_clEnqueueMapImage)(
     cl_command_queue command_queue, cl_mem image, cl_bool blocking_map,
     cl_map_flags map_flags, const size_t *origin, const size_t *region,
     size_t *image_row_pitch, size_t *image_slice_pitch,
     cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
     cl_event *event, cl_int *errcode_ret)CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueUnmapMemObject)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueUnmapMemObject)(
     cl_command_queue command_queue, cl_mem memobj, void *mapped_ptr,
     cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_0;
 
 #ifdef CL_VERSION_1_2
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueMigrateMemObjects)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueMigrateMemObjects)(
     cl_command_queue command_queue, cl_uint num_mem_objects,
     const cl_mem *mem_objects, cl_mem_migration_flags flags,
     cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
@@ -604,19 +604,19 @@ typedef void *cl_api_clEnqueueMigrateMem
 
 #endif
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueNDRangeKernel)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueNDRangeKernel)(
     cl_command_queue command_queue, cl_kernel kernel, cl_uint work_dim,
     const size_t *global_work_offset, const size_t *global_work_size,
     const size_t *local_work_size, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueTask)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueTask)(
     cl_command_queue command_queue, cl_kernel kernel,
     cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueNativeKernel)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueNativeKernel)(
     cl_command_queue command_queue, void(CL_CALLBACK *user_func)(void *),
     void *args, size_t cb_args, cl_uint num_mem_objects, const cl_mem *mem_list,
     const void **args_mem_loc, cl_uint num_events_in_wait_list,
@@ -625,17 +625,17 @@ typedef CL_API_ENTRY cl_int(CL_API_CALL 
 
 #ifdef CL_VERSION_1_2
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueMarkerWithWaitList)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueMarkerWithWaitList)(
     cl_command_queue command_queue, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueBarrierWithWaitList)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueBarrierWithWaitList)(
     cl_command_queue command_queue, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY void *(
+typedef void *(
     CL_API_CALL *cl_api_clGetExtensionFunctionAddressForPlatform)(
     cl_platform_id platform,
     const char *function_name)CL_API_SUFFIX__VERSION_1_2;
@@ -652,7 +652,7 @@ typedef void *cl_api_clGetExtensionFunct
 
 #ifdef CL_VERSION_2_0
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueSVMFree)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueSVMFree)(
     cl_command_queue /* command_queue */, cl_uint /* num_svm_pointers */,
     void ** /* svm_pointers */,
     void(CL_CALLBACK *pfn_free_func)(cl_command_queue /* queue */,
@@ -663,28 +663,28 @@ typedef CL_API_ENTRY cl_int(CL_API_CALL 
     const cl_event * /* event_wait_list */,
     cl_event * /* event */) CL_API_SUFFIX__VERSION_2_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueSVMMemcpy)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueSVMMemcpy)(
     cl_command_queue /* command_queue */, cl_bool /* blocking_copy */,
     void * /* dst_ptr */, const void * /* src_ptr */, size_t /* size */,
     cl_uint /* num_events_in_wait_list */,
     const cl_event * /* event_wait_list */,
     cl_event * /* event */) CL_API_SUFFIX__VERSION_2_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueSVMMemFill)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueSVMMemFill)(
     cl_command_queue /* command_queue */, void * /* svm_ptr */,
     const void * /* pattern */, size_t /* pattern_size */, size_t /* size */,
     cl_uint /* num_events_in_wait_list */,
     const cl_event * /* event_wait_list */,
     cl_event * /* event */) CL_API_SUFFIX__VERSION_2_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueSVMMap)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueSVMMap)(
     cl_command_queue /* command_queue */, cl_bool /* blocking_map */,
     cl_map_flags /* map_flags */, void * /* svm_ptr */, size_t /* size */,
     cl_uint /* num_events_in_wait_list */,
     const cl_event * /* event_wait_list */,
     cl_event * /* event */) CL_API_SUFFIX__VERSION_2_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueSVMUnmap)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueSVMUnmap)(
     cl_command_queue /* command_queue */, void * /* svm_ptr */,
     cl_uint /* num_events_in_wait_list */,
     const cl_event * /* event_wait_list */,
@@ -701,119 +701,119 @@ typedef void *cl_api_clEnqueueSVMUnmap;
 #endif
 
 // Deprecated APIs
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clSetCommandQueueProperty)(
+typedef cl_int(CL_API_CALL *cl_api_clSetCommandQueueProperty)(
     cl_command_queue command_queue, cl_command_queue_properties properties,
     cl_bool enable, cl_command_queue_properties *old_properties)
-    CL_EXT_SUFFIX__VERSION_1_0_DEPRECATED;
+    CL_API_SUFFIX__VERSION_1_0_DEPRECATED;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateImage2D)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateImage2D)(
     cl_context context, cl_mem_flags flags, const cl_image_format *image_format,
     size_t image_width, size_t image_height, size_t image_row_pitch,
-    void *host_ptr, cl_int *errcode_ret) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+    void *host_ptr, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateImage3D)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateImage3D)(
     cl_context context, cl_mem_flags flags, const cl_image_format *image_format,
     size_t image_width, size_t image_height, size_t image_depth,
     size_t image_row_pitch, size_t image_slice_pitch, void *host_ptr,
-    cl_int *errcode_ret) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+    cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clUnloadCompiler)(void)
-    CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+typedef cl_int(CL_API_CALL *cl_api_clUnloadCompiler)(void)
+    CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueMarker)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueMarker)(
     cl_command_queue command_queue,
-    cl_event *event) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+    cl_event *event) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueWaitForEvents)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueWaitForEvents)(
     cl_command_queue command_queue, cl_uint num_events,
-    const cl_event *event_list) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+    const cl_event *event_list) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueBarrier)(
-    cl_command_queue command_queue) CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueBarrier)(
+    cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
-typedef CL_API_ENTRY void *(CL_API_CALL *cl_api_clGetExtensionFunctionAddress)(
-    const char *function_name)CL_EXT_SUFFIX__VERSION_1_1_DEPRECATED;
+typedef void *(CL_API_CALL *cl_api_clGetExtensionFunctionAddress)(
+    const char *function_name)CL_API_SUFFIX__VERSION_1_1_DEPRECATED;
 
 // GL and other APIs
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateFromGLBuffer)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateFromGLBuffer)(
     cl_context context, cl_mem_flags flags, cl_GLuint bufobj,
     int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateFromGLTexture)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateFromGLTexture)(
     cl_context context, cl_mem_flags flags, cl_GLenum target, cl_GLint miplevel,
     cl_GLuint texture, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateFromGLTexture2D)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateFromGLTexture2D)(
     cl_context context, cl_mem_flags flags, cl_GLenum target, cl_GLint miplevel,
     cl_GLuint texture, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateFromGLTexture3D)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateFromGLTexture3D)(
     cl_context context, cl_mem_flags flags, cl_GLenum target, cl_GLint miplevel,
     cl_GLuint texture, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateFromGLRenderbuffer)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateFromGLRenderbuffer)(
     cl_context context, cl_mem_flags flags, cl_GLuint renderbuffer,
     cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetGLObjectInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetGLObjectInfo)(
     cl_mem memobj, cl_gl_object_type *gl_object_type,
     cl_GLuint *gl_object_name) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetGLTextureInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetGLTextureInfo)(
     cl_mem memobj, cl_gl_texture_info param_name, size_t param_value_size,
     void *param_value, size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueAcquireGLObjects)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueAcquireGLObjects)(
     cl_command_queue command_queue, cl_uint num_objects,
     const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueReleaseGLObjects)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueReleaseGLObjects)(
     cl_command_queue command_queue, cl_uint num_objects,
     const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_0;
 
 /* cl_khr_gl_sharing */
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetGLContextInfoKHR)(
+typedef cl_int(CL_API_CALL *cl_api_clGetGLContextInfoKHR)(
     const cl_context_properties *properties, cl_gl_context_info param_name,
     size_t param_value_size, void *param_value, size_t *param_value_size_ret);
 
 /* cl_khr_gl_event */
-typedef CL_API_ENTRY cl_event(CL_API_CALL *cl_api_clCreateEventFromGLsyncKHR)(
+typedef cl_event(CL_API_CALL *cl_api_clCreateEventFromGLsyncKHR)(
     cl_context context, cl_GLsync sync, cl_int *errcode_ret);
 
 #if defined(_WIN32)
 
 /* cl_khr_d3d10_sharing */
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetDeviceIDsFromD3D10KHR)(
+typedef cl_int(CL_API_CALL *cl_api_clGetDeviceIDsFromD3D10KHR)(
     cl_platform_id platform, cl_d3d10_device_source_khr d3d_device_source,
     void *d3d_object, cl_d3d10_device_set_khr d3d_device_set,
     cl_uint num_entries, cl_device_id *devices,
     cl_uint *num_devices) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateFromD3D10BufferKHR)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateFromD3D10BufferKHR)(
     cl_context context, cl_mem_flags flags, ID3D10Buffer *resource,
     cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateFromD3D10Texture2DKHR)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateFromD3D10Texture2DKHR)(
     cl_context context, cl_mem_flags flags, ID3D10Texture2D *resource,
     UINT subresource, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateFromD3D10Texture3DKHR)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateFromD3D10Texture3DKHR)(
     cl_context context, cl_mem_flags flags, ID3D10Texture3D *resource,
     UINT subresource, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY
+typedef
 cl_int(CL_API_CALL *cl_api_clEnqueueAcquireD3D10ObjectsKHR)(
     cl_command_queue command_queue, cl_uint num_objects,
     const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY
+typedef
 cl_int(CL_API_CALL *cl_api_clEnqueueReleaseD3D10ObjectsKHR)(
     cl_command_queue command_queue, cl_uint num_objects,
     const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
@@ -848,32 +848,32 @@ extern CL_API_ENTRY cl_int CL_API_CALL c
     const cl_event *event_wait_list, cl_event *event);
 
 /* cl_khr_d3d11_sharing */
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetDeviceIDsFromD3D11KHR)(
+typedef cl_int(CL_API_CALL *cl_api_clGetDeviceIDsFromD3D11KHR)(
     cl_platform_id platform, cl_d3d11_device_source_khr d3d_device_source,
     void *d3d_object, cl_d3d11_device_set_khr d3d_device_set,
     cl_uint num_entries, cl_device_id *devices,
     cl_uint *num_devices) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateFromD3D11BufferKHR)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateFromD3D11BufferKHR)(
     cl_context context, cl_mem_flags flags, ID3D11Buffer *resource,
     cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateFromD3D11Texture2DKHR)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateFromD3D11Texture2DKHR)(
     cl_context context, cl_mem_flags flags, ID3D11Texture2D *resource,
     UINT subresource, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateFromD3D11Texture3DKHR)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateFromD3D11Texture3DKHR)(
     cl_context context, cl_mem_flags flags, ID3D11Texture3D *resource,
     UINT subresource, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY
+typedef
 cl_int(CL_API_CALL *cl_api_clEnqueueAcquireD3D11ObjectsKHR)(
     cl_command_queue command_queue, cl_uint num_objects,
     const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY
+typedef
 cl_int(CL_API_CALL *cl_api_clEnqueueReleaseD3D11ObjectsKHR)(
     cl_command_queue command_queue, cl_uint num_objects,
     const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
@@ -881,26 +881,26 @@ cl_int(CL_API_CALL *cl_api_clEnqueueRele
     cl_event *event) CL_API_SUFFIX__VERSION_1_2;
 
 /* cl_khr_dx9_media_sharing */
-typedef CL_API_ENTRY
+typedef
 cl_int(CL_API_CALL *cl_api_clGetDeviceIDsFromDX9MediaAdapterKHR)(
     cl_platform_id platform, cl_uint num_media_adapters,
     cl_dx9_media_adapter_type_khr *media_adapters_type, void *media_adapters,
     cl_dx9_media_adapter_set_khr media_adapter_set, cl_uint num_entries,
     cl_device_id *devices, cl_uint *num_devices) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateFromDX9MediaSurfaceKHR)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateFromDX9MediaSurfaceKHR)(
     cl_context context, cl_mem_flags flags,
     cl_dx9_media_adapter_type_khr adapter_type, void *surface_info,
     cl_uint plane, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY
+typedef
 cl_int(CL_API_CALL *cl_api_clEnqueueAcquireDX9MediaSurfacesKHR)(
     cl_command_queue command_queue, cl_uint num_objects,
     const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_1_2;
 
-typedef CL_API_ENTRY
+typedef
 cl_int(CL_API_CALL *cl_api_clEnqueueReleaseDX9MediaSurfacesKHR)(
     cl_command_queue command_queue, cl_uint num_objects,
     const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
@@ -987,29 +987,29 @@ typedef void *cl_api_clGetDeviceIDsFromD
 
 #ifdef CL_VERSION_1_1
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clSetEventCallback)(
+typedef cl_int(CL_API_CALL *cl_api_clSetEventCallback)(
     cl_event /* event */, cl_int /* command_exec_callback_type */,
     void(CL_CALLBACK * /* pfn_notify */)(cl_event, cl_int, void *),
     void * /* user_data */) CL_API_SUFFIX__VERSION_1_1;
 
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateSubBuffer)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateSubBuffer)(
     cl_mem /* buffer */, cl_mem_flags /* flags */,
     cl_buffer_create_type /* buffer_create_type */,
     const void * /* buffer_create_info */,
     cl_int * /* errcode_ret */) CL_API_SUFFIX__VERSION_1_1;
 
-typedef CL_API_ENTRY
+typedef
 cl_int(CL_API_CALL *cl_api_clSetMemObjectDestructorCallback)(
     cl_mem /* memobj */,
     void(CL_CALLBACK * /*pfn_notify*/)(cl_mem /* memobj */,
                                        void * /*user_data*/),
     void * /*user_data */) CL_API_SUFFIX__VERSION_1_1;
 
-typedef CL_API_ENTRY cl_event(CL_API_CALL *cl_api_clCreateUserEvent)(
+typedef cl_event(CL_API_CALL *cl_api_clCreateUserEvent)(
     cl_context /* context */,
     cl_int * /* errcode_ret */) CL_API_SUFFIX__VERSION_1_1;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clSetUserEventStatus)(
+typedef cl_int(CL_API_CALL *cl_api_clSetUserEventStatus)(
     cl_event /* event */,
     cl_int /* execution_status */) CL_API_SUFFIX__VERSION_1_1;
 
@@ -1023,68 +1023,68 @@ typedef void *cl_api_clSetUserEventStatu
 
 #endif
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clCreateSubDevicesEXT)(
+typedef cl_int(CL_API_CALL *cl_api_clCreateSubDevicesEXT)(
     cl_device_id in_device,
     const cl_device_partition_property_ext *partition_properties,
     cl_uint num_entries, cl_device_id *out_devices, cl_uint *num_devices);
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clRetainDeviceEXT)(
+typedef cl_int(CL_API_CALL *cl_api_clRetainDeviceEXT)(
     cl_device_id device) CL_API_SUFFIX__VERSION_1_0;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clReleaseDeviceEXT)(
+typedef cl_int(CL_API_CALL *cl_api_clReleaseDeviceEXT)(
     cl_device_id device) CL_API_SUFFIX__VERSION_1_0;
 
 /* cl_khr_egl_image */
-typedef CL_API_ENTRY cl_mem(CL_API_CALL *cl_api_clCreateFromEGLImageKHR)(
+typedef cl_mem(CL_API_CALL *cl_api_clCreateFromEGLImageKHR)(
     cl_context context, CLeglDisplayKHR display, CLeglImageKHR image,
     cl_mem_flags flags, const cl_egl_image_properties_khr *properties,
     cl_int *errcode_ret);
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueAcquireEGLObjectsKHR)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueAcquireEGLObjectsKHR)(
     cl_command_queue command_queue, cl_uint num_objects,
     const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list, cl_event *event);
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueReleaseEGLObjectsKHR)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueReleaseEGLObjectsKHR)(
     cl_command_queue command_queue, cl_uint num_objects,
     const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list, cl_event *event);
 
 /* cl_khr_egl_event */
-typedef CL_API_ENTRY cl_event(CL_API_CALL *cl_api_clCreateEventFromEGLSyncKHR)(
+typedef cl_event(CL_API_CALL *cl_api_clCreateEventFromEGLSyncKHR)(
     cl_context context, CLeglSyncKHR sync, CLeglDisplayKHR display,
     cl_int *errcode_ret);
 
 #ifdef CL_VERSION_2_1
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clSetDefaultDeviceCommandQueue)(
+typedef cl_int(CL_API_CALL *cl_api_clSetDefaultDeviceCommandQueue)(
     cl_context context, cl_device_id device,
     cl_command_queue command_queue) CL_API_SUFFIX__VERSION_2_1;
 
-typedef CL_API_ENTRY cl_program(CL_API_CALL *cl_api_clCreateProgramWithIL)(
+typedef cl_program(CL_API_CALL *cl_api_clCreateProgramWithIL)(
     cl_context context, const void *il, size_t length,
     cl_int *errcode_ret) CL_API_SUFFIX__VERSION_2_1;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetKernelSubGroupInfo)(
+typedef cl_int(CL_API_CALL *cl_api_clGetKernelSubGroupInfo)(
     cl_kernel kernel, cl_device_id device, cl_kernel_sub_group_info param_name,
     size_t input_value_size, const void *input_value, size_t param_value_size,
     void *param_value, size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_2_1;
 
-typedef CL_API_ENTRY cl_kernel(CL_API_CALL *cl_api_clCloneKernel)(
+typedef cl_kernel(CL_API_CALL *cl_api_clCloneKernel)(
     cl_kernel source_kernel, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_2_1;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clEnqueueSVMMigrateMem)(
+typedef cl_int(CL_API_CALL *cl_api_clEnqueueSVMMigrateMem)(
     cl_command_queue command_queue, cl_uint num_svm_pointers,
     const void **svm_pointers, const size_t *sizes,
     cl_mem_migration_flags flags, cl_uint num_events_in_wait_list,
     const cl_event *event_wait_list,
     cl_event *event) CL_API_SUFFIX__VERSION_2_1;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetDeviceAndHostTimer)(
+typedef cl_int(CL_API_CALL *cl_api_clGetDeviceAndHostTimer)(
     cl_device_id device, cl_ulong *device_timestamp,
     cl_ulong *host_timestamp) CL_API_SUFFIX__VERSION_2_1;
 
-typedef CL_API_ENTRY cl_int(CL_API_CALL *cl_api_clGetHostTimer)(
+typedef cl_int(CL_API_CALL *cl_api_clGetHostTimer)(
     cl_device_id device, cl_ulong *host_timestamp) CL_API_SUFFIX__VERSION_2_1;
 
 #else
