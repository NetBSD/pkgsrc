$NetBSD: patch-khronos-headers_CL_cl__layer.h,v 1.1 2021/06/10 05:55:42 nia Exp $

[PATCH] Updated to support latest Khronos headers.

Signed-off-by: Laurent Carlier <lordheavym@gmail.com>

--- khronos-headers/CL/cl_layer.h.orig	2021-03-30 16:10:38.000000000 +0000
+++ khronos-headers/CL/cl_layer.h
@@ -36,7 +36,7 @@ clGetLayerInfo(cl_layer_info  param_name
                void          *param_value,
                size_t        *param_value_size_ret);
 
-CL_API_ENTRY typedef cl_int
+typedef cl_int
 (CL_API_CALL *pfn_clGetLayerInfo)(cl_layer_info  param_name,
                                   size_t         param_value_size,
                                   void          *param_value,
@@ -48,7 +48,7 @@ clInitLayer(cl_uint                 num_
             cl_uint                *num_entries_ret,
             const cl_icd_dispatch **layer_dispatch_ret);
 
-CL_API_ENTRY typedef cl_int
+typedef cl_int
 (CL_API_CALL *pfn_clInitLayer)(cl_uint                 num_entries,
                                const cl_icd_dispatch  *target_dispatch,
                                cl_uint                *num_entries_ret,
