$NetBSD: patch-src_uri.cc,v 1.1 2013/03/31 08:18:58 sbd Exp $

--- src/uri.cc.orig	2008-04-05 23:49:24.000000000 +0000
+++ src/uri.cc
@@ -40,6 +40,7 @@
 #include <glibmm.h>
 #include <iostream>
 #include <cstring>
+#include <cstdio>
 
 #include "debug.hh"
 #include "uri.hh"
@@ -227,7 +228,7 @@ char *path_escape(const char *path)
     	if (path_escape_ch(*pnt))
       {
 	    /* Escape it - %<hex><hex> */
-	    sprintf(p, "%%%02x", (unsigned char) *pnt);
+	    std::sprintf(p, "%%%02x", (unsigned char) *pnt);
 	    p += 3;
 	    } else {
 	      *p++ = *pnt;
