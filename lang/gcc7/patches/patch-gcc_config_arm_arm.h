$NetBSD: patch-gcc_config_arm_arm.h,v 1.1 2017/05/03 00:21:03 maya Exp $

driver-arm.o is only included for freebsd/arm and linux/arm, and
it is responsible for the definition of host_detect_local_cpu.

Without it, we get an undefined reference.

GCC bugzilla #77800

--- gcc/config/arm/arm.h.orig	2016-12-15 17:51:46.000000000 +0000
+++ gcc/config/arm/arm.h
@@ -2231,7 +2231,7 @@ extern const char *arm_target_thumb_only
 
 /* -mcpu=native handling only makes sense with compiler running on
    an ARM chip.  */
-#if defined(__arm__)
+#if defined(__arm__) && (defined(__linux__) || defined(__FreeBSD__))
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 # define EXTRA_SPEC_FUNCTIONS						\
   { "local_cpu_detect", host_detect_local_cpu },			\
