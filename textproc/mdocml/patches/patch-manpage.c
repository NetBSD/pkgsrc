$NetBSD: patch-manpage.c,v 1.1 2015/12/10 02:50:19 joerg Exp $

--- manpage.c.orig	2015-12-07 15:20:30.565955584 +0000
+++ manpage.c
@@ -20,7 +20,6 @@
 #include <sys/types.h>
 
 #include <assert.h>
-#include <getopt.h>
 #include <limits.h>
 #include <stdint.h>
 #include <stdio.h>
