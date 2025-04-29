$NetBSD: patch-percent__x.c,v 1.2 2025/04/29 14:18:00 tnn Exp $

--- percent_x.c.orig	1994-12-28 16:42:38.000000000 +0000
+++ percent_x.c
@@ -19,8 +19,9 @@ static char sccsid[] = "@(#) percent_x.c
 #include <stdio.h>
 #include <syslog.h>
 #include <string.h>
+#include <unistd.h>
 
-extern void exit();
+#include <stdlib.h>
 
 /* Local stuff. */
 
