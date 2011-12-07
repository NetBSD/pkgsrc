$NetBSD: patch-rw_readWriteXBM.c,v 1.1.2.2 2011/12/07 08:30:52 tron Exp $

--- rw/readWriteXBM.c.orig	2011-12-05 20:26:00.000000000 +0000
+++ rw/readWriteXBM.c
@@ -16,8 +16,7 @@
 
 #include <stdio.h>
+#include <string.h>
 #include "image.h"
 
-int strncmp(char *, char *, int);
-
 #define TRUE 1
 #define FALSE 0
@@ -57,7 +56,4 @@ int strncmp(char *, char *, int);
 #include <ctype.h>
 
-extern char *strrchr(char *, char);
-
-
 #define MAX_SIZE 255
 #define True 1
