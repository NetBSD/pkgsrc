$NetBSD: patch-gcc_config_openbsd.h,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- gcc/config/openbsd.h.orig	2010-12-22 12:06:01.000000000 +0000
+++ gcc/config/openbsd.h
@@ -109,9 +109,9 @@ while (0)
    This two-stage defines makes it easy to pick that for targets that
    have subspecs.  */
 #ifdef CPP_CPU_SPEC
-#define OBSD_CPP_SPEC "%(cpp_cpu) %{posix:-D_POSIX_SOURCE} %{pthread:-D_POSIX_THREADS}"
+#define OBSD_CPP_SPEC "%(cpp_cpu) %{posix:-D_POSIX_SOURCE} %{pthread:-D_REENTRANT}"
 #else
-#define OBSD_CPP_SPEC "%{posix:-D_POSIX_SOURCE} %{pthread:-D_POSIX_THREADS}"
+#define OBSD_CPP_SPEC "%{posix:-D_POSIX_SOURCE} %{pthread:-D_REENTRANT}"
 #endif
 
 #undef LIB_SPEC
