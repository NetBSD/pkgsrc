$NetBSD: patch-lib_fascist.c,v 1.1 2020/11/22 11:36:32 nia Exp $

Argument to ctype functions must be unsigned char.

--- lib/fascist.c.orig	2019-02-14 01:54:41.000000000 +0000
+++ lib/fascist.c
@@ -28,7 +28,7 @@ typedef unsigned short uint16_t;
 
 #include "packer.h"
 
-#define ISSKIP(x) (isspace(x) || ispunct(x))
+#define ISSKIP(x) (isspace((unsigned char)x) || ispunct((unsigned char)x))
 
 #define MINDIFF 5
 #define MINLEN 6
@@ -744,7 +744,7 @@ FascistLookUser(PWDICT *pwp, char *instr
 
     Trim(password);
 
-    while (*password && isspace(*password))
+    while (*password && isspace((unsigned char)*password))
     {
 	password++;
     }
