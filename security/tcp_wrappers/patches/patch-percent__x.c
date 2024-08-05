$NetBSD: patch-percent__x.c,v 1.1 2024/08/05 12:48:18 tnn Exp $

--- percent_x.c.orig	2024-08-05 13:52:09.983774379 +0000
+++ percent_x.c
@@ -19,6 +19,7 @@ static char sccsid[] = "@(#) percent_x.c
 #include <stdio.h>
 #include <syslog.h>
 #include <string.h>
+#include <unistd.h>
 
 extern void exit();
 
