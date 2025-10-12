$NetBSD: patch-src_aasavefont.c,v 1.1 2025/10/12 01:32:11 mrg Exp $

Add missing headers.


--- src/aasavefont.c.orig	2001-04-26 07:37:31.000000000 -0700
+++ src/aasavefont.c	2025-10-11 18:27:01.386739535 -0700
@@ -1,3 +1,4 @@
+#include <stdlib.h>
 #include "aalib.h"
 int main(int argc, char **argv)
 {
