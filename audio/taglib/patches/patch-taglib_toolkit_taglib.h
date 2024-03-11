$NetBSD: patch-taglib_toolkit_taglib.h,v 1.1 2024/03/11 09:11:01 jperkin Exp $

illumos headers define offset_t.

--- taglib/toolkit/taglib.h.orig	2024-03-11 09:08:42.276396541 +0000
+++ taglib/toolkit/taglib.h
@@ -60,7 +60,7 @@ namespace TagLib {
   // In Win32, always 64bit. Otherwise, equivalent to off_t.
 #ifdef _WIN32
   using offset_t = long long;
-#else
+#elif !defined(__illumos__)
   using offset_t = off_t;
 #endif
 
