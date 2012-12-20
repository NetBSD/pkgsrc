$NetBSD: patch-simpledic.c,v 1.1 2012/12/20 21:50:47 joerg Exp $

--- simpledic.c.orig	2012-12-20 14:41:29.000000000 +0000
+++ simpledic.c
@@ -3,6 +3,8 @@
 #include <sys/types.h>
 #include "skklib.h"
 
+void closeSKK(Dictionary dic, char *dicname);
+
 main() 
 {
 	Dictionary dic;
