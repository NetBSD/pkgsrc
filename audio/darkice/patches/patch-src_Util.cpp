$NetBSD: patch-src_Util.cpp,v 1.2 2012/02/08 00:19:42 sbd Exp $

--- src/Util.cpp.orig	2005-04-17 10:58:09.000000000 +0000
+++ src/Util.cpp
@@ -276,7 +276,7 @@ Util :: fileAddDate ( const char * str )
     unsigned int    size;
     char          * s;
     char          * strdate;
-    char          * last;
+    const char    * last;
     time_t          now;
     
     if ( !str ) {
