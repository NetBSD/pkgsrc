$NetBSD: patch-src_argp-local.h,v 1.1 2011/11/24 13:56:02 joerg Exp $

--- src/argp-local.h.orig	2011-11-24 00:53:41.000000000 +0000
+++ src/argp-local.h
@@ -10,6 +10,7 @@
 //
 
 #include <getopt.h>
+#include <stdlib.h>
 #include <string.h>
 #include <iostream>
 
