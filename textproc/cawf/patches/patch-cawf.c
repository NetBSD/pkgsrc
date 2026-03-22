$NetBSD: patch-cawf.c,v 1.1 2026/03/22 10:31:53 nia Exp $

Include <unistd.h> so we use the system getopt(3).

Modern GCC no longer likes implicit int.

--- cawf.c.orig	1997-02-22 08:26:16.000000000 +0000
+++ cawf.c
@@ -36,6 +36,7 @@ static char Version[] = "4.10";
 #include "cawf.h"
 
 #include <time.h>
+#include <unistd.h>
 
 #include <sys/stat.h>
 
@@ -60,7 +61,7 @@ static char *Month[] =
 	{ "January", "February", "March", "April", "May", "June", "July",
 	  "August", "September", "October", "November", "December" };
 
-
+int
 main(argc, argv)
 	int     argc;
 	char    *argv[];
