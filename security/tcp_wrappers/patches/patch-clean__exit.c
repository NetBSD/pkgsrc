$NetBSD: patch-clean__exit.c,v 1.1 2024/08/05 12:48:18 tnn Exp $

--- clean_exit.c.orig	2024-08-05 13:51:37.866956280 +0000
+++ clean_exit.c
@@ -13,6 +13,7 @@ static char sccsid[] = "@(#) clean_exit.
 #endif
 
 #include <stdio.h>
+#include <unistd.h>
 
 extern void exit();
 
