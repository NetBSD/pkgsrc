$NetBSD: patch-gcc_config_aarch64_aarch64.h,v 1.1 2018/11/09 11:22:13 mrg Exp $

support arm64.

--- gcc/config/aarch64/aarch64.h.orig	2017-09-21 12:16:31.000000000 +0000
+++ gcc/config/aarch64/aarch64.h	2018-11-09 09:37:45.295152705 +0000
@@ -930,7 +930,7 @@
 #define MCPU_TO_MARCH_SPEC_FUNCTIONS \
   { "rewrite_mcpu", aarch64_rewrite_mcpu },
 
-#if defined(__aarch64__)
+#if defined(__aarch64__) && !defined(__NetBSD__)
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 # define EXTRA_SPEC_FUNCTIONS						\
   { "local_cpu_detect", host_detect_local_cpu },			\
