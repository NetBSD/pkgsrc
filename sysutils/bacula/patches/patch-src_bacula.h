$NetBSD: patch-src_bacula.h,v 1.1 2014/02/01 19:41:31 joerg Exp $

--- src/bacula.h.orig	2014-01-31 20:01:28.000000000 +0000
+++ src/bacula.h
@@ -186,6 +186,8 @@ extern "C" {
 #undef _
 #undef free
 #undef malloc
+#undef Enter
+#undef Leave
 #endif
 
 #if defined(HAVE_WIN32)
