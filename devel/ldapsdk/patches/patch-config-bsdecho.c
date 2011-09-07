$NetBSD: patch-config-bsdecho.c,v 1.1 2011/09/07 23:44:28 joerg Exp $

--- config/bsdecho.c.orig	2011-09-07 14:40:08.000000000 +0000
+++ config/bsdecho.c
@@ -34,7 +34,7 @@
 #include "sunos4.h"
 #endif
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
 	short numargs = argc;
 	short newline = 1;
