$NetBSD: patch-src_aakbdreg.c,v 1.1 2025/10/12 01:32:11 mrg Exp $

Add missing headers.


--- src/aakbdreg.c.orig	2025-10-11 18:15:55.419041548 -0700
+++ src/aakbdreg.c	2025-10-11 18:16:32.655834758 -0700
@@ -1,4 +1,5 @@
 #include <malloc.h>
+#include <string.h>
 #include "config.h"
 #include "aalib.h"
 #include "aaint.h"
