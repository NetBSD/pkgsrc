$NetBSD: patch-src_debug.cc,v 1.1 2012/11/16 20:05:35 joerg Exp $

--- src/debug.cc.orig	2012-11-16 14:01:18.000000000 +0000
+++ src/debug.cc
@@ -76,8 +76,7 @@ namespace Bmp
 
   void
   debug (const std::string &domain,
-         const std::string &format,
-         ...)
+         const char *format, ...)
   {
       if( !use_debug )
         return;
@@ -88,7 +87,7 @@ namespace Bmp
 
           va_start (args, format);
           std::string domain_full = std::string("bmpx-") + domain;
-          g_logv (domain_full.c_str (), G_LOG_LEVEL_INFO, format.c_str (), args);
+          g_logv (domain_full.c_str (), G_LOG_LEVEL_INFO, format, args);
           va_end (args);
       }
   }
