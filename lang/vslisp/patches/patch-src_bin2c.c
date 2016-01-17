$NetBSD: patch-src_bin2c.c,v 1.1 2016/01/17 15:14:47 joerg Exp $

--- src/bin2c.c.orig	2016-01-16 13:47:40.000000000 +0000
+++ src/bin2c.c
@@ -1,3 +1,4 @@
+#include <stdlib.h>
 #include <stdio.h>
 
 int main(int np,char **p)
