$NetBSD: patch-tkined_generic_tkiInit.c,v 1.1 2016/05/02 04:00:25 dholland Exp $

Don't demand exactly TCL_VERSION and TK_VERSION as these do not
include the patchlevel (e.g. they're 8.6 instead of 8.6.5).

--- tkined/generic/tkiInit.c~	1998-09-16 17:11:01.000000000 +0000
+++ tkined/generic/tkiInit.c
@@ -62,11 +62,11 @@ TkiInit(interp)
 
     buffersize(1024);
 
-    if (Tcl_PkgRequire(interp, "Tcl", TCL_VERSION, 1) == NULL) {
+    if (Tcl_PkgRequire(interp, "Tcl", TCL_VERSION, 0) == NULL) {
         return TCL_ERROR;
     }
 
-    if (Tcl_PkgRequire(interp, "Tk", TK_VERSION, 1) == NULL) {
+    if (Tcl_PkgRequire(interp, "Tk", TK_VERSION, 0) == NULL) {
         return TCL_ERROR;
     }
 
