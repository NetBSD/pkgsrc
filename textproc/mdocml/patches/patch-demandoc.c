$NetBSD: patch-demandoc.c,v 1.1 2015/12/10 02:50:19 joerg Exp $

--- demandoc.c.orig	2015-12-07 15:20:07.413956576 +0000
+++ demandoc.c
@@ -20,7 +20,6 @@
 
 #include <assert.h>
 #include <ctype.h>
-#include <getopt.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
