$NetBSD: patch-unix_tclUnixFCmd.c,v 1.2 2014/01/11 14:41:05 adam Exp $

Carried over from TCL 8.4

--- unix/tclUnixFCmd.c.orig	2012-07-16 11:57:06.000000000 +0000
+++ unix/tclUnixFCmd.c
@@ -676,6 +676,14 @@ TclpDeleteFile(
  *---------------------------------------------------------------------------
  */
 
+/* Reintroduced here for the benefit of scotty */
+int
+TclpCreateDirectory(path)
+    CONST char *path;
+{
+    return DoCreateDirectory(path);
+}
+
 int
 TclpObjCreateDirectory(
     Tcl_Obj *pathPtr)
