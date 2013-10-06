$NetBSD: patch-main.c,v 1.1 2013/10/06 17:15:35 adam Exp $

Avoid double symbols: define one global variable 'streaming'.

--- main.c.orig	2013-03-29 22:22:24.000000000 +0000
+++ main.c
@@ -32,6 +32,8 @@
 #include <paper.h>
 #endif
 
+int streaming;
+
 /*
  * Most of this file deals with command line options, by exploiting
  * the cmdline.[ch] engine to offer defaults via environment variables
