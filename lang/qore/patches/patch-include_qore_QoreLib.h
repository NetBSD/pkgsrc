$NetBSD: patch-include_qore_QoreLib.h,v 1.1 2016/03/09 21:32:41 nros Exp $
* Fix build with open/libressl releases without evp_SHA
  https://github.com/qorelanguage/qore/commit/fc181070ad1afbf49af2e8fc968b97328d690a86
--- include/qore/QoreLib.h.orig	2016-03-09 20:32:22.000000000 +0000
+++ include/qore/QoreLib.h
@@ -372,6 +372,8 @@ DLLEXPORT const char* tz_get_region_name
 #define QORE_OPT_RUNTIME_STACK_TRACE     "runtime stack tracing"
 //! option: library debugging
 #define QORE_OPT_LIBRARY_DEBUGGING       "library debugging"
+//! option: ssh0 algorithm supported (depends on openssl used to compile qore)
+#define QORE_OPT_SHA                     "openssl sha"
 //! option: ssh224 algorithm supported (depends on openssl used to compile qore)
 #define QORE_OPT_SHA224                  "openssl sha224"
 //! option: ssh256 algorithm supported (depends on openssl used to compile qore) 
