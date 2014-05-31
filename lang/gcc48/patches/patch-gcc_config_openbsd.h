$NetBSD: patch-gcc_config_openbsd.h,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- gcc/config/openbsd.h.orig	2013-01-10 20:38:27.000000000 +0000
+++ gcc/config/openbsd.h
@@ -108,9 +108,9 @@ while (0)
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
@@ -283,5 +283,15 @@ do {									 \
 
 /* Storage layout.  */
 
+/*
+ * Disable the use of unsafe builtin functions, (strcat, strcpy, stpcpy),
+ * making them easier to spot in the object files.
+ */
+#define NO_UNSAFE_BUILTINS
+
+/* The system headers on OpenBSD are C++-aware.  */
+#undef NO_IMPLICIT_EXTERN_C
+#define NO_IMPLICIT_EXTERN_C
+
 
 #define HAVE_ENABLE_EXECUTE_STACK
