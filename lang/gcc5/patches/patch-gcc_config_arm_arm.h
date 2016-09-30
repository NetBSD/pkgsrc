$NetBSD: patch-gcc_config_arm_arm.h,v 1.1 2016/09/30 04:06:07 maya Exp $

needs host_extra_gcc_objs="driver-arm.o" in gcc/config.host.
otherwise you get an error:
undefined reference to `host_detect_local_cpu(int, char const**)

the function relies on /proc/cpuinfo to exist and provide useful
information, and is used for -m{arch,tune,cpu}=native.

--- gcc/config/arm/arm.h.orig	2016-03-29 13:28:34.000000000 +0000
+++ gcc/config/arm/arm.h
@@ -2394,7 +2394,7 @@ extern const char *arm_rewrite_mcpu (int
 
 /* -mcpu=native handling only makes sense with compiler running on
    an ARM chip.  */
-#if defined(__arm__)
+#if defined(__arm__) && (defined(__linux__) || defined(__FreeBSD__))
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 # define EXTRA_SPEC_FUNCTIONS						\
   { "local_cpu_detect", host_detect_local_cpu },			\
