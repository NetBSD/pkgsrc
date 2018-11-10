$NetBSD: patch-gcc_config_aarch64_aarch64.h,v 1.1 2018/11/10 11:45:27 mrg Exp $

support arm64.

--- gcc/config/aarch64/aarch64.h.orig	2018-02-21 14:05:45.000000000 +0000
+++ gcc/config/aarch64/aarch64.h	2018-11-09 12:07:14.375232698 +0000
@@ -1000,7 +1000,7 @@
 #define MCPU_TO_MARCH_SPEC_FUNCTIONS \
   { "rewrite_mcpu", aarch64_rewrite_mcpu },
 
-#if defined(__aarch64__)
+#if defined(__aarch64__) && !defined(__NetBSD__)
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 #define HAVE_LOCAL_CPU_DETECT
 # define EXTRA_SPEC_FUNCTIONS						\
