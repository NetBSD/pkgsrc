$NetBSD: patch-src_zm__regexp.cpp,v 1.1 2026/01/07 01:05:07 gdt Exp $

--- src/zm_regexp.cpp.orig	2026-01-07 00:38:46.457884202 +0000
+++ src/zm_regexp.cpp
@@ -33,7 +33,7 @@ RegExpr::RegExpr( const char *pattern, i
   {
     PCRE2_UCHAR buffer[256];
     pcre2_get_error_message(errorcode, buffer, sizeof(buffer));
-    Panic( "pcre2_compile(%s): %s at %ld", pattern, buffer, erroffset );
+    Panic( "pcre2_compile(%s): %s at %jd", pattern, buffer, static_cast<intmax_t>(erroffset) );
   }
 
   if ( (ok = (bool)regex) )
