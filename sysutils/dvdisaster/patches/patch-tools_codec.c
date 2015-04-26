$NetBSD: patch-tools_codec.c,v 1.1 2015/04/26 13:30:58 joerg Exp $

--- tools/codec.c.orig	2015-04-26 12:06:58.000000000 +0000
+++ tools/codec.c
@@ -20,6 +20,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #include <bzlib.h>
 
