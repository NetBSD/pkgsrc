$NetBSD: patch-src_aafire.c,v 1.1 2025/10/12 01:32:11 mrg Exp $

Add missing headers.


--- src/aafire.c.orig	2001-04-26 08:30:03.000000000 -0700
+++ src/aafire.c	2025-10-11 18:24:48.142846732 -0700
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <stdlib.h>
 #include "aalib.h"
 
 #define XSIZ aa_imgwidth(context)
