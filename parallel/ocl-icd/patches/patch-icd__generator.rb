$NetBSD: patch-icd__generator.rb,v 1.1 2021/06/10 05:55:42 nia Exp $

[PATCH] Updated to support latest Khronos headers.

Signed-off-by: Laurent Carlier <lordheavym@gmail.com>

--- icd_generator.rb.orig	2021-03-30 16:10:38.000000000 +0000
+++ icd_generator.rb
@@ -57,7 +57,7 @@ module IcdGenerator
                          "clGetGLContextInfoKHR", "clUnloadCompiler",
     "clCreateContext", "clCreateContextFromType", "clWaitForEvents"]
   $header_files = ["/usr/include/CL/cl.h", "/usr/include/CL/cl_gl.h", "/usr/include/CL/cl_egl.h",
-    "/usr/include/CL/cl_ext.h", "/usr/include/CL/cl_gl_ext.h"]
+    "/usr/include/CL/cl_ext.h"]
   $windows_header_files = ["/usr/include/CL/cl_dx9_media_sharing.h", "/usr/include/CL/cl_d3d11.h", "/usr/include/CL/cl_d3d10.h"]
   $cl_data_type_error = { "cl_platform_id"   => "CL_INVALID_PLATFORM",
                           "cl_device_id"     => "CL_INVALID_DEVICE",
@@ -246,7 +246,7 @@ EOF
     run_dummy_icd += "\n\n"
     $api_entries.each_key { |func_name|
        next if $forbidden_funcs.include?(func_name)
-       run_dummy_icd += $api_entries[func_name]+";\n"
+       run_dummy_icd += $api_entries[func_name]+"\n"
     }
     run_dummy_icd += "\n\n"
     run_dummy_icd += "void call_all_OpenCL_functions(cl_platform_id chosen_platform) {\n"
