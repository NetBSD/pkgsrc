$NetBSD: patch-unix_tnmUnixIcmp.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- unix/tnmUnixIcmp.c~	1997-08-26 18:55:44.000000000 +0000
+++ unix/tnmUnixIcmp.c
@@ -61,7 +61,7 @@ ForkNtping(interp)
     Tcl_Interp *interp;
 {
     int argc = 2;
-    static char *argv[3] = { NULL, "-b", 0 };
+    static const char *argv[3] = { NULL, "-b", 0 };
     static char* ntping = NULL;
 
     if (! ntping) {
