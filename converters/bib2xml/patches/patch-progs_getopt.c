$NetBSD: patch-progs_getopt.c,v 1.1 2025/11/26 08:30:25 wiz Exp $

Add missing headers.

--- progs/getopt.c.orig	2025-11-26 08:26:29.963735320 +0000
+++ progs/getopt.c
@@ -46,6 +46,7 @@
 #endif
 
 #include <stdio.h>
+#include <string.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
    actually compiling the library itself.  This code is part of the GNU C
