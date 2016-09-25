$NetBSD: patch-gcc_config_arm_arm.h,v 1.1 2016/09/25 23:09:35 maya Exp $

Don't declare a prototype used for -march=native, avoids build error on netbsd/arm:
gcc.o:(.rodata+0x58c4): undefined reference to `host_detect_local_cpu(int, char const**)'

same change is used in netbsd base gcc.

--- gcc/config/arm/arm.h.orig	2015-01-14 11:02:24.000000000 +0000
+++ gcc/config/arm/arm.h
@@ -2315,7 +2315,7 @@ extern int making_const_table;
 
 /* -mcpu=native handling only makes sense with compiler running on
    an ARM chip.  */
-#if defined(__arm__)
+#if defined(__arm__) && !defined(__NetBSD__)
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 # define EXTRA_SPEC_FUNCTIONS						\
   { "local_cpu_detect", host_detect_local_cpu },
