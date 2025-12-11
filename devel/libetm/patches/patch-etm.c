$NetBSD: patch-etm.c,v 1.1 2025/12/11 21:28:58 vins Exp $

* Add missing includes.
* Prevent implicit int.

--- etm.c.orig	1997-04-10 20:13:05.000000000 +0000
+++ etm.c
@@ -48,6 +48,8 @@
 */
 
 # include	<stdio.h>
+# include       <stdlib.h>
+# include       <string.h>
 # include	<signal.h>
 # include	<sys/types.h>
 # ifdef	STDARGS
@@ -333,6 +335,7 @@ ETMSigCatcher	*cp;
 
 
 ETMProcPtr ETMGetSignalProc (signo)
+int     signo;
 {
 ETMSigCatcher	*cp;
 
