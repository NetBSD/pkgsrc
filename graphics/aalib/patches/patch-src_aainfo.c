$NetBSD: patch-src_aainfo.c,v 1.1 2025/10/12 01:32:11 mrg Exp $

Add missing headers.


--- src/aainfo.c.orig	2001-04-26 07:37:31.000000000 -0700
+++ src/aainfo.c	2025-10-11 18:23:19.636856818 -0700
@@ -1,3 +1,4 @@
+#include <stdlib.h>
 
 #include "aalib.h"
 #include "aaint.h"
