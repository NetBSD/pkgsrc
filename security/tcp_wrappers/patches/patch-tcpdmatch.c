$NetBSD: patch-tcpdmatch.c,v 1.2 2025/04/29 14:18:00 tnn Exp $

--- tcpdmatch.c.orig	1999-10-27 14:16:35.000000000 +0000
+++ tcpdmatch.c
@@ -29,8 +29,9 @@ static char sccsid[] = "@(#) tcpdmatch.c
 #include <syslog.h>
 #include <setjmp.h>
 #include <string.h>
+#include <unistd.h>
+#include <stdlib.h>
 
-extern void exit();
 extern int optind;
 extern char *optarg;
 
@@ -48,8 +49,8 @@ extern char *optarg;
 #include "inetcf.h"
 #include "scaffold.h"
 
-static void usage();
-static void tcpdmatch();
+static void usage(char *);
+static void tcpdmatch(struct request_info *);
 
 /* The main program */
 
