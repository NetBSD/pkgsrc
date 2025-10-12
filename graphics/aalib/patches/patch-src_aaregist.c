$NetBSD: patch-src_aaregist.c,v 1.1 2025/10/12 01:32:11 mrg Exp $

Add missing headers.


--- src/aaregist.c.orig	2001-04-26 07:37:31.000000000 -0700
+++ src/aaregist.c	2025-10-11 18:15:05.227568205 -0700
@@ -1,4 +1,5 @@
 #include <malloc.h>
+#include <string.h>
 #include "config.h"
 #include "aalib.h"
 #include "aaint.h"
