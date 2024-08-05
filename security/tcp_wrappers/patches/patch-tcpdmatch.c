$NetBSD: patch-tcpdmatch.c,v 1.1 2024/08/05 12:48:18 tnn Exp $

--- tcpdmatch.c.orig	2024-08-05 14:09:19.243824349 +0000
+++ tcpdmatch.c
@@ -29,6 +29,8 @@ static char sccsid[] = "@(#) tcpdmatch.c
 #include <syslog.h>
 #include <setjmp.h>
 #include <string.h>
+#include <unistd.h>
+#include <stdlib.h>
 
 extern void exit();
 extern int optind;
