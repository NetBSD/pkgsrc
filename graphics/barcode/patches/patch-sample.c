$NetBSD: patch-sample.c,v 1.1 2013/10/06 17:15:35 adam Exp $

Avoid double symbols: define one global variable 'streaming'.

--- sample.c.orig	2013-10-06 07:47:28.000000000 +0000
+++ sample.c
@@ -4,6 +4,8 @@
 #include <stdlib.h>
 #include <string.h>
 
+int streaming;
+
 int main(int argc, char **argv)
 {
     int pcl = 0, oflags;
