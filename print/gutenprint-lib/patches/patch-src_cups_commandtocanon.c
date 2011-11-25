$NetBSD: patch-src_cups_commandtocanon.c,v 1.1 2011/11/25 22:17:08 joerg Exp $

--- src/cups/commandtocanon.c.orig	2011-11-25 18:21:02.000000000 +0000
+++ src/cups/commandtocanon.c
@@ -13,6 +13,7 @@
 
 #include <cups/cups.h>
 #include <ctype.h>
+#include <stdio.h>
 #include <stdlib.h>
 
 
