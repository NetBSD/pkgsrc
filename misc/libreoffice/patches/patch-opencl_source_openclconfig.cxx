$NetBSD: patch-opencl_source_openclconfig.cxx,v 1.1 2018/04/19 18:07:03 mrg Exp $

add missing ICU namespace needed for icu 61.

--- opencl/source/openclconfig.cxx.orig	2018-03-29 08:04:09.000000000 -0700
+++ opencl/source/openclconfig.cxx	2018-04-17 18:02:24.130022792 -0700
@@ -17,6 +17,8 @@
 #include <sal/log.hxx>
 #include <sal/types.h>
 
+using namespace U_ICU_NAMESPACE;
+
 OpenCLConfig::OpenCLConfig() :
     mbUseOpenCL(true)
 {
