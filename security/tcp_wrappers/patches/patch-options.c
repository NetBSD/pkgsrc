$NetBSD: patch-options.c,v 1.1 2024/08/05 12:48:18 tnn Exp $

--- options.c.orig	2024-08-05 14:07:29.242137802 +0000
+++ options.c
@@ -47,6 +47,8 @@ static char sccsid[] = "@(#) options.c 1
 #include <ctype.h>
 #include <setjmp.h>
 #include <string.h>
+#include <unistd.h>
+#include <stdlib.h>
 
 #ifndef MAXPATHNAMELEN
 #define MAXPATHNAMELEN  BUFSIZ
