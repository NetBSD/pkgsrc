$NetBSD: patch-unix_tnmUnixLog.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- unix/tnmUnixLog.c~	1996-09-10 11:35:33.000000000 +0200
+++ unix/tnmUnixLog.c	2014-03-04 18:06:44.000000000 +0100
@@ -36,7 +36,7 @@
 TnmWriteLogMessage(interp, level, message)
     Tcl_Interp *interp;
     int level;
-    char *message;
+    const char *message;
 {
     switch (level) {
       case TNM_LOG_EMERG:
