$NetBSD: patch-libgcc_config_i386_cpuinfo.h,v 1.1 2017/05/04 17:38:23 maya Exp $

Fix GCC bug #80600

--- libgcc/config/i386/cpuinfo.h.orig	2017-01-10 12:55:41.000000000 +0000
+++ libgcc/config/i386/cpuinfo.h
@@ -108,7 +108,7 @@ enum processor_features
   FEATURE_AVX512VPOPCNTDQ
 };
 
-extern struct __processor_model
+struct __processor_model
 {
   unsigned int __cpu_vendor;
   unsigned int __cpu_type;
