$NetBSD: patch-src_Util.cpp,v 1.1 2012/02/04 07:53:26 sbd Exp $

--- src/Util.cpp.orig	2005-04-17 10:58:09.000000000 +0000
+++ src/Util.cpp
@@ -288,7 +288,7 @@ Util :: fileAddDate ( const char * str )
     strftime( strdate, 128, "[%m-%d-%Y-%H-%M-%S]", localtime (&now));
 
     // search for the part before the extension of the file name
-    if ( !(last = strrchr( str, '.')) ) {
+    if ( !(last = (char *) strrchr( str, '.')) ) {
         last = (char *) str + strlen( str);
     }
 
