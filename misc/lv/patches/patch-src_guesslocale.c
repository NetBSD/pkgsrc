$NetBSD: patch-src_guesslocale.c,v 1.1 2024/08/09 03:34:13 ryoon Exp $

* For toupper().

--- src/guesslocale.c.orig	2024-08-08 02:01:56.304541089 +0000
+++ src/guesslocale.c
@@ -33,6 +33,7 @@
 #include <ctable.h>
 #include <begin.h>
 #include <guesslocale.h>
+#include <ctype.h>
 
 static int strcmp2( char *str1, char *str2 )
 {
