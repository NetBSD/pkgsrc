$NetBSD: patch-gcc_config_arm_arm.h,v 1.1 2020/02/11 01:04:05 mrg Exp $

Disable -march=native for cross compilers.


--- gcc/config/arm/arm.h.orig	2018-03-22 10:24:41.000000000 -0700
+++ gcc/config/arm/arm.h	2020-02-10 16:39:34.594580129 -0800
@@ -2194,8 +2194,8 @@
   { "target_mode_check", arm_target_thumb_only },
 
 /* -mcpu=native handling only makes sense with compiler running on
-   an ARM chip.  */
-#if defined(__arm__)
+   an ARM chip.  Cross compile hosts may not be able to do this.  */
+#if defined(__arm__) && !defined(CROSS_DIRECTORY_STRUCTURE)
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 #define HAVE_LOCAL_CPU_DETECT
 # define MCPU_MTUNE_NATIVE_FUNCTIONS			\
