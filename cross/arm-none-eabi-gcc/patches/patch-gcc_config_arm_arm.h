$NetBSD: patch-gcc_config_arm_arm.h,v 1.2 2025/09/04 23:06:24 lloyd Exp $

--- gcc/config/arm/arm.h.orig	2025-05-23 11:02:04.304197710 +0000
+++ gcc/config/arm/arm.h
@@ -2493,8 +2493,8 @@ extern const char *arm_target_mode (int 
   { "target_mode_check", arm_target_mode },
 
 /* -mcpu=native handling only makes sense with compiler running on
-   an ARM chip.  */
-#if defined(__arm__)
+   an ARM chip.  Cross compile hosts may not be able to do this.  */
+#if defined(__arm__) && !defined(CROSS_DIRECTORY_STRUCTURE)
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 #define HAVE_LOCAL_CPU_DETECT
 # define MCPU_MTUNE_NATIVE_FUNCTIONS			\
