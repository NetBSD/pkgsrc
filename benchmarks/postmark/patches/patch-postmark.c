$NetBSD: patch-postmark.c,v 1.1 2025/10/07 03:56:29 mrg Exp $

Include <unistd.h> for read()/write()/rmdir() and sys/stat.h for mkdir(),
and give main a return type.  Makes GCC 14 happy.


--- postmark.c.orig	2025-09-29 15:03:55.078573258 -0700
+++ postmark.c	2025-09-29 15:05:33.243049771 -0700
@@ -51,6 +51,8 @@ Versions:
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
+#include <unistd.h>
+#include <sys/stat.h>
 #include <time.h>
 #include <fcntl.h>
 
@@ -1228,7 +1230,7 @@ char *buffer;   /* temp storage for each
 }
 
 /* main function - reads config files then enters get line/parse line loop */
-main(argc,argv)
+int main(argc,argv)
 int argc;
 char *argv[];
 {
