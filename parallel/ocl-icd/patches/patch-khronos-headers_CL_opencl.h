$NetBSD: patch-khronos-headers_CL_opencl.h,v 1.1 2021/06/10 05:55:42 nia Exp $

[PATCH] Updated to support latest Khronos headers.

Signed-off-by: Laurent Carlier <lordheavym@gmail.com>

--- khronos-headers/CL/opencl.h.orig	2021-03-30 16:10:38.000000000 +0000
+++ khronos-headers/CL/opencl.h
@@ -1,5 +1,5 @@
 /*******************************************************************************
- * Copyright (c) 2008-2020 The Khronos Group Inc.
+ * Copyright (c) 2008-2021 The Khronos Group Inc.
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
@@ -23,7 +23,6 @@ extern "C" {
 
 #include <CL/cl.h>
 #include <CL/cl_gl.h>
-#include <CL/cl_gl_ext.h>
 #include <CL/cl_ext.h>
 
 #ifdef __cplusplus
