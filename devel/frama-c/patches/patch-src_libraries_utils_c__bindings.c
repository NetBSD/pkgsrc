$NetBSD: patch-src_libraries_utils_c__bindings.c,v 1.1 2017/09/05 07:30:00 dholland Exp $

sync ifdefs with reality

--- src/libraries/utils/c_bindings.c~	2017-06-01 08:02:15.000000000 +0000
+++ src/libraries/utils/c_bindings.c
@@ -35,7 +35,7 @@
 #include <unistd.h>
 
 // Some BSD flavors do not implement all of C99
-#if defined(__OpenBSD__) || defined(__NetBSD__) 
+#if defined(__OpenBSD__)
 # include <ieeefp.h>
 # define FE_DOWNWARD FP_RM
 # define FE_UPWARD FP_RP
@@ -218,7 +218,7 @@ value single_precision_of_string(value s
 value terminate_process(value v) 
 {
   long pid = Long_val(v);
-#if _POSIX_C_SOURCE >= 1 || _XOPEN_SOURCE || _POSIX_SOURCE || __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ 
+#if _POSIX_C_SOURCE >= 1 || _XOPEN_SOURCE || _POSIX_SOURCE || __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined (__Bitrig__)
   kill(pid,9);
 #else
  #ifdef _WIN32
