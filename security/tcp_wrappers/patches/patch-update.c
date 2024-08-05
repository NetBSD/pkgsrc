$NetBSD: patch-update.c,v 1.1 2024/08/05 12:48:18 tnn Exp $

--- update.c.orig	2024-08-05 14:10:29.935491528 +0000
+++ update.c
@@ -22,6 +22,7 @@ static char sccsid[] = "@(#) update.c 1.
 #include <stdio.h>
 #include <syslog.h>
 #include <string.h>
+#include <unistd.h>
 
 /* Local stuff. */
 
