$NetBSD: patch-src_debug.hh,v 1.1 2012/11/16 20:05:35 joerg Exp $

--- src/debug.hh.orig	2012-11-16 14:00:54.000000000 +0000
+++ src/debug.hh
@@ -37,9 +37,7 @@ namespace Bmp
   debug_init ();
 
   void
-  debug (const std::string &domain,
-         const std::string &format,
-         ...);
+  debug (const std::string &domain, const char *format, ...);
 }
 
 #endif // BMP_DEBUG_HPP
