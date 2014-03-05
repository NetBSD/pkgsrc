$NetBSD: patch-tnm_generic_tnmSyslog.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/generic/tnmSyslog.c~	1996-07-31 08:37:31.000000000 +0200
+++ tnm/generic/tnmSyslog.c	2014-03-04 16:04:23.000000000 +0100
@@ -47,7 +47,7 @@
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     int level;
 
