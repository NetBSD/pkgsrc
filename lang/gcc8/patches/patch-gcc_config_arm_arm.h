$NetBSD: patch-gcc_config_arm_arm.h,v 1.2 2019/04/18 19:18:02 rillig Exp $

driver-arm.o is only included for freebsd/arm and linux/arm, and
it is responsible for the definition of host_detect_local_cpu.

Without it, we get an undefined reference.

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=77800

--- gcc/config/arm/arm.h.orig	2018-03-22 17:24:41.000000000 +0000
+++ gcc/config/arm/arm.h
@@ -2195,7 +2195,7 @@ extern const char *arm_target_thumb_only
 
 /* -mcpu=native handling only makes sense with compiler running on
    an ARM chip.  */
-#if defined(__arm__)
+#if defined(__arm__) && (defined(__linux__) || defined(__FreeBSD__))
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 #define HAVE_LOCAL_CPU_DETECT
 # define MCPU_MTUNE_NATIVE_FUNCTIONS			\
