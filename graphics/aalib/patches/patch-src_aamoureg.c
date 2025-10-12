$NetBSD: patch-src_aamoureg.c,v 1.1 2025/10/12 01:32:11 mrg Exp $

Add missing headers.


--- src/aamoureg.c.orig	2025-10-11 18:20:28.987180916 -0700
+++ src/aamoureg.c	2025-10-11 18:20:54.713495805 -0700
@@ -1,4 +1,5 @@
 #include <malloc.h>
+#include <string.h>
 #include "config.h"
 #include "aalib.h"
 #include "aaint.h"
