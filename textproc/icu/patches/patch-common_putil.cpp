$NetBSD: patch-common_putil.cpp,v 1.2 2015/10/09 23:15:34 ryoon Exp $

--- common/putil.cpp.orig	2015-10-08 03:53:44.000000000 +0000
+++ common/putil.cpp
@@ -117,6 +117,14 @@
 #endif
 
 /*
+ * Mac OS X 10.4 doesn't use its localtime_r() declaration in <time.h> if either _ANSI_SOURCE or _POSIX_C_SOURCE is #defined.
+ */
+#if defined(U_TZNAME) && U_PLATFORM_IS_DARWIN_BASED && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ == 1040 \
+	&& (defined(_ANSI_SOURCE) || defined(_POSIX_C_SOURCE))
+U_CFUNC struct tm *localtime_r(const time_t *, struct tm *);
+#endif
+
+/*
  * Only include langinfo.h if we have a way to get the codeset. If we later
  * depend on more feature, we can test on U_HAVE_NL_LANGINFO.
  *
