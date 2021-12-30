$NetBSD: patch-password.c,v 1.1 2021/12/30 00:43:35 nia Exp $

Need string.h for strcpy().

--- password.c.orig	1997-04-20 21:48:36.000000000 +0000
+++ password.c
@@ -50,6 +50,7 @@ extern char    *password;
 #define SECURE_PASSWD
 #endif
 #include <unistd.h>
+#include <string.h>
 
 int
 matchesPassword (char *guess, int allowroot)
