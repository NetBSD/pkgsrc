$NetBSD: patch-file.c,v 1.1 2013/05/23 14:57:32 joerg Exp $

--- file.c.orig	1999-11-09 07:23:46.000000000 +0000
+++ file.c
@@ -7,6 +7,8 @@
 #include "str.h"
 #include "tai.h"
 #include "env.h"
+#include "open.h"
+#include "exit.h"
 
 static void log(char *fn,char *result1,char *result2,int flagread)
 {
