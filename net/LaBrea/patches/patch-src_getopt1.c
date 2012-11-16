$NetBSD: patch-src_getopt1.c,v 1.1 2012/11/16 20:10:21 joerg Exp $

--- src/getopt1.c.orig	2003-09-09 20:55:03.000000000 +0000
+++ src/getopt1.c
@@ -22,7 +22,7 @@
 #include "config.h"
 #endif
 
-#include "getopt.h"
+#include "../inc/getopt.h"
 
 #if !defined __STDC__ || !__STDC__
 /* This is a separate conditional since some stdc systems
