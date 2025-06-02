$NetBSD: patch-main.c,v 1.1 2025/06/02 11:16:24 vins Exp $

Silence size mismatch warnings.

--- main.c.orig	1997-08-30 18:08:39.000000000 +0000
+++ main.c
@@ -35,6 +35,7 @@
  *      muquit@semcor.com   31-Aug-95   first cut
  */
 
+#include <stdint.h>
 #include "xhead.h"
 
 #define __Main__
@@ -219,7 +220,7 @@ char
     XtAppAddInput(app,stderr_pipe[0],
         (XtPointer) XtInputReadMask,
         (XtInputCallbackProc) DoStderr,
-        (XtPointer) stderr_pipe[0]);
+        (XtPointer)(intptr_t) stderr_pipe[0]);
 
     XtAppMainLoop(app);
 }
@@ -294,7 +295,7 @@ XtInputId
     *id;
 {
     int
-        fd=(int) client_data;
+        fd=(intptr_t) client_data;
 
     char
         buf[512];
