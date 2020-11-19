$NetBSD: patch-include_dosbox.h,v 1.1 2020/11/19 17:17:15 nia Exp $

Only attempt to use long double on x86.

--- include/dosbox.h.orig	2020-11-01 15:36:10.000000000 +0000
+++ include/dosbox.h
@@ -72,9 +72,7 @@
 // TODO: The autoconf script should test the size of long double
 #if defined(_MSC_VER)
 // Microsoft C++ sizeof(long double) == sizeof(double)
-#elif defined(__arm__)
-// ARMv7 (Raspberry Pi) does not have long double, sizeof(long double) == sizeof(double)
-#else
+#elif C_TARGETCPU == X86_64 || C_TARGETCPU == X86
 // GCC, other compilers, have sizeof(long double) == 10 80-bit IEEE
 # define HAS_LONG_DOUBLE		1
 #endif
