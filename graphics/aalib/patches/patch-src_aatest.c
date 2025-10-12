$NetBSD: patch-src_aatest.c,v 1.1 2025/10/12 01:32:11 mrg Exp $

Add missing headers.


--- src/aatest.c.orig	2001-04-26 07:37:31.000000000 -0700
+++ src/aatest.c	2025-10-11 18:24:00.561876515 -0700
@@ -1,3 +1,5 @@
+#include <stdlib.h>
+#include <string.h>
 #include "aalib.h"
 int main(int argc, char **argv)
 {
