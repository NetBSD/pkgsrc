$NetBSD: patch-run__dummy__icd.c,v 1.1 2021/06/10 05:55:42 nia Exp $

[PATCH] Updated to support latest Khronos headers.

Signed-off-by: Laurent Carlier <lordheavym@gmail.com>

--- run_dummy_icd.c.orig	2021-03-30 16:10:38.000000000 +0000
+++ run_dummy_icd.c
@@ -39,7 +39,6 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
 #  include <CL/cl_gl.h>
 #  include <CL/cl_egl.h>
 #  include <CL/cl_ext.h>
-#  include <CL/cl_gl_ext.h>
 #pragma GCC diagnostic pop
 #include <string.h>
 #include "ocl_icd_debug.h"
