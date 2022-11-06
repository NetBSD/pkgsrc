$NetBSD: patch-include_dosbox.h,v 1.3 2022/11/06 21:31:57 triaxx Exp $

GCC having 80-bit long double is far from a safe assumption.

--- include/dosbox.h.orig	2022-09-01 22:55:29.000000000 +0000
+++ include/dosbox.h
@@ -68,19 +68,6 @@
 # define pref_struct_stat	struct stat
 #endif
 
-// TODO: The autoconf script should test the size of long double
-#if defined(_MSC_VER)
-// Microsoft C++ sizeof(long double) == sizeof(double)
-#undef HAS_LONG_DOUBLE
-#elif defined(__arm__) || defined(__aarch64__)
-// ARMv7 (Raspberry Pi) does not have long double, sizeof(long double) == sizeof(double)
-// ARM 64 has a quadruple-precision float instead of the 80-bit extended precision one used by x87
-#undef HAS_LONG_DOUBLE
-#else
-// GCC, other compilers, have sizeof(long double) == 10 80-bit IEEE
-#define HAS_LONG_DOUBLE		1
-#endif
-
 GCC_ATTRIBUTE(noreturn) void		E_Exit(const char * format,...) GCC_ATTRIBUTE( __format__(__printf__, 1, 2));
 
 typedef Bits cpu_cycles_count_t;
