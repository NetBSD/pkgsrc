$NetBSD: patch-src_slang.h,v 1.1 2025/01/06 21:36:25 ktnb Exp $

--- src/slang.h.orig	2007-10-28 18:37:14.000000000 -0400
+++ src/slang.h
@@ -43,6 +43,11 @@ USA.  
 # endif
 #endif /* __watcomc__ */
 
+#if defined(__NetBSD__) || defined(__APPLE__)
+#undef unix
+#define unix 1
+#endif
+
 #if defined(unix) || defined(__unix)
 # ifndef __unix__
 #  define __unix__ 1
