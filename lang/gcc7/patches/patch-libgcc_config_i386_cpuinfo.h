$NetBSD: patch-libgcc_config_i386_cpuinfo.h,v 1.3 2017/07/05 10:17:01 adam Exp $

ifdef out extern for GCC bug #80600, with the same condition as
cpuinfo.c. removing triggers GCC bug #65612

--- libgcc/config/i386/cpuinfo.h.orig	2017-01-10 12:55:41.000000000 +0000
+++ libgcc/config/i386/cpuinfo.h
@@ -108,7 +108,10 @@ enum processor_features
   FEATURE_AVX512VPOPCNTDQ
 };
 
-extern struct __processor_model
+#if defined(__APPLE__) || (defined SHARED && defined USE_ELF_SYMVER)
+extern
+#endif
+struct __processor_model
 {
   unsigned int __cpu_vendor;
   unsigned int __cpu_type;
