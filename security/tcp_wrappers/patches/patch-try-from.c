$NetBSD: patch-try-from.c,v 1.1 2024/08/05 12:48:18 tnn Exp $

--- try-from.c.orig	2024-08-05 14:13:01.123642876 +0000
+++ try-from.c
@@ -37,6 +37,7 @@ static char sccsid[] = "@(#) try-from.c
 int     allow_severity = SEVERITY;	/* run-time adjustable */
 int     deny_severity = LOG_WARNING;	/* ditto */
 
+int
 main(argc, argv)
 int     argc;
 char  **argv;
