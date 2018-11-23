$NetBSD: patch-gcc_config_aarch64_aarch64.h,v 1.2 2018/11/23 05:30:45 ryoon Exp $

driver-aarch64.o is not included for NetBSD and it is responsible for
the definition of host_detect_local_cpu.

Without it, we get an undefined reference.

Similar to GCC bugzilla #77800 for arm.

--- gcc/config/aarch64/aarch64.h.orig	2018-02-21 14:05:45.000000000 +0000
+++ gcc/config/aarch64/aarch64.h
@@ -1000,7 +1000,8 @@ extern const char *aarch64_rewrite_mcpu 
 #define MCPU_TO_MARCH_SPEC_FUNCTIONS \
   { "rewrite_mcpu", aarch64_rewrite_mcpu },
 
-#if defined(__aarch64__)
+/* NetBSD does not export necessary info via /proc/cpuinfo. */
+#if defined(__aarch64__) && !defined(__NetBSD__)
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 #define HAVE_LOCAL_CPU_DETECT
 # define EXTRA_SPEC_FUNCTIONS						\
