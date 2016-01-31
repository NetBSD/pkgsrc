$NetBSD: patch-lib_string.in.h,v 1.2 2016/01/31 09:20:51 ryoon Exp $

* fixes for nested include of string.h.

--- lib/string.in.h.orig	2016-01-01 14:17:01.000000000 +0000
+++ lib/string.in.h
@@ -32,12 +32,18 @@
 #else
 /* Normal invocation convention.  */
 
+#ifdef GL_ALREADY_INCLUDE_STRING_H
+#@INCLUDE_NEXT@ @NEXT_STRING_H@
+#else
+
 #ifndef _@GUARD_PREFIX@_STRING_H
 
 #define _GL_ALREADY_INCLUDING_STRING_H
 
+#define GL_ALREADY_INCLUDE_STRING_H
 /* The include_next requires a split double-inclusion guard.  */
 #@INCLUDE_NEXT@ @NEXT_STRING_H@
+#undef GL_ALREADY_INCLUDE_STRING_H
 
 #undef _GL_ALREADY_INCLUDING_STRING_H
 
@@ -1044,3 +1050,4 @@ _GL_WARN_ON_USE (strverscmp, "strverscmp
 #endif /* _@GUARD_PREFIX@_STRING_H */
 #endif /* _@GUARD_PREFIX@_STRING_H */
 #endif
+#endif
