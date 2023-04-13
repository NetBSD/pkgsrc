$NetBSD: patch-src_lxplib.c,v 1.1 2023/04/13 19:03:25 joerg Exp $

--- src/lxplib.c.orig	2023-04-13 18:47:18.513590552 +0000
+++ src/lxplib.c
@@ -9,7 +9,6 @@
 #include <stdlib.h>
 #include <string.h>
 
-#include "expat_config.h"
 #include "expat.h"
 #if (XML_MAJOR_VERSION == 2 && XML_MINOR_VERSION < 4) || (XML_MAJOR_VERSION < 2)
 #error Expat 2.4 or newer is required
