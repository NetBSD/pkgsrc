$NetBSD: patch-include_dosbox.h,v 1.2 2021/01/05 11:01:49 nia Exp $

GCC having 80-bit long double is far from a safe assumption.

--- include/dosbox.h.orig	2020-12-01 02:49:53.000000000 +0000
+++ include/dosbox.h
@@ -69,16 +69,6 @@
 # define pref_struct_stat	struct stat
 #endif
 
-// TODO: The autoconf script should test the size of long double
-#if defined(_MSC_VER)
-// Microsoft C++ sizeof(long double) == sizeof(double)
-#elif defined(__arm__)
-// ARMv7 (Raspberry Pi) does not have long double, sizeof(long double) == sizeof(double)
-#else
-// GCC, other compilers, have sizeof(long double) == 10 80-bit IEEE
-# define HAS_LONG_DOUBLE		1
-#endif
-
 GCC_ATTRIBUTE(noreturn) void		E_Exit(const char * format,...) GCC_ATTRIBUTE( __format__(__printf__, 1, 2));
 
 typedef Bits cpu_cycles_count_t;
