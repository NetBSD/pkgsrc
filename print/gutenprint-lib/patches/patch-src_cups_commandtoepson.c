$NetBSD: patch-src_cups_commandtoepson.c,v 1.1 2011/11/25 22:17:08 joerg Exp $

--- src/cups/commandtoepson.c.orig	2011-11-25 18:20:47.000000000 +0000
+++ src/cups/commandtoepson.c
@@ -30,6 +30,7 @@
 
 #include <cups/cups.h>
 #include <ctype.h>
+#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
