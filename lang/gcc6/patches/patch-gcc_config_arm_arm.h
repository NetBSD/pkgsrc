$NetBSD: patch-gcc_config_arm_arm.h,v 1.1 2017/05/28 01:22:38 maya Exp $

driver-arm.o is only included for freebsd/arm and linux/arm, and
it is responsible for the definition of host_detect_local_cpu.

Without it, we get an undefined reference.

GCC bugzilla #77800

--- gcc/config/arm/arm.h.orig	2016-04-01 14:58:53.000000000 +0000
+++ gcc/config/arm/arm.h
@@ -2247,7 +2247,7 @@ extern const char *arm_rewrite_mcpu (int
 
 /* -mcpu=native handling only makes sense with compiler running on
    an ARM chip.  */
-#if defined(__arm__)
+#if defined(__arm__) && (defined(__linux__) || defined(__FreeBSD__))
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 # define EXTRA_SPEC_FUNCTIONS						\
   { "local_cpu_detect", host_detect_local_cpu },			\
