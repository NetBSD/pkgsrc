$NetBSD: patch-tnm_generic_tnmRpc.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/generic/tnmRpc.c~	1997-12-23 09:49:11.000000000 +0100
+++ tnm/generic/tnmRpc.c	2014-03-04 14:14:17.000000000 +0100
@@ -263,7 +263,7 @@
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     return TCL_OK;
 }
@@ -1152,7 +1152,7 @@
      ClientData clientData;
      Tcl_Interp *interp;
      int argc;
-     char **argv;
+     const char **argv;
 {
     int len;
 
