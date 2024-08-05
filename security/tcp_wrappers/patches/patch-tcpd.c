$NetBSD: patch-tcpd.c,v 1.1 2024/08/05 12:48:18 tnn Exp $

--- tcpd.c.orig	2024-08-05 14:09:09.673677618 +0000
+++ tcpd.c
@@ -24,6 +24,7 @@ static char sccsid[] = "@(#) tcpd.c 1.10
 #include <stdio.h>
 #include <syslog.h>
 #include <string.h>
+#include <unistd.h>
 
 #ifndef MAXPATHNAMELEN
 #define MAXPATHNAMELEN	BUFSIZ
@@ -41,6 +42,7 @@ static char sccsid[] = "@(#) tcpd.c 1.10
 int     allow_severity = SEVERITY;	/* run-time adjustable */
 int     deny_severity = LOG_WARNING;	/* ditto */
 
+int
 main(argc, argv)
 int     argc;
 char  **argv;
