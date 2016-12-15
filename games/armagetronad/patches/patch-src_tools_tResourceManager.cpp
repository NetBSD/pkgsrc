$NetBSD: patch-src_tools_tResourceManager.cpp,v 1.1 2016/12/15 23:52:43 joerg Exp $

fopen returns a NULL pointer on failure.

--- src/tools/tResourceManager.cpp.orig	2016-12-15 17:37:32.864347941 +0000
+++ src/tools/tResourceManager.cpp
@@ -44,7 +44,7 @@ static int myHTTPFetch(const char *URI, 
     }
 
     fd = fopen(savepath, "w");
-    if (fd < 0) {
+    if (fd == NULL) {
         xmlNanoHTTPClose(ctxt);
         con << tOutput( "$resource_no_write", savepath );
         return 3;
