$NetBSD: patch-gcc_config_aarch64_aarch64.h,v 1.1 2018/11/08 23:28:28 mrg Exp $

driver-aarch64.o is not included for NetBSD and it is responsible for
the definition of host_detect_local_cpu.

Without it, we get an undefined reference.

Similar to GCC bugzilla #77800 for arm.

--- gcc/config/aarch64/aarch64.h.orig	2017-01-19 15:51:49.000000000 -0800
+++ gcc/config/aarch64/aarch64.h	2018-11-08 14:31:59.315619048 -0800
@@ -930,7 +930,8 @@
 #define MCPU_TO_MARCH_SPEC_FUNCTIONS \
   { "rewrite_mcpu", aarch64_rewrite_mcpu },
 
-#if defined(__aarch64__)
+/* NetBSD does not export necessary info via /proc/cpuinfo. */
+#if defined(__aarch64__) && !defined(__NetBSD__)
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 # define EXTRA_SPEC_FUNCTIONS						\
   { "local_cpu_detect", host_detect_local_cpu },			\
