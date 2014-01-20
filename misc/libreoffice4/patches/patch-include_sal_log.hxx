$NetBSD: patch-include_sal_log.hxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- include/sal/log.hxx.orig	2013-10-22 17:49:23.000000000 +0000
+++ include/sal/log.hxx
@@ -157,9 +157,13 @@ inline char const * unwrapStream(SAL_UNU
 
     @since LibreOffice 3.5
 */
+#ifdef _LIBCPP_VERSION
 #define SAL_STREAM(stream) \
-    (dynamic_cast< ::std::ostringstream & >(::std::ostringstream() << stream). \
-     str())
+    (::std::ostringstream() << stream).str()
+#else
+#define SAL_STREAM(stream) \
+    (dynamic_cast< ::std::ostringstream & >(::std::ostringstream() << stream).str())
+#endif
 
 /**
     @page sal_log Basic logging functionality.
