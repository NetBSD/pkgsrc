$NetBSD: patch-src_randnum.c,v 1.1 2021/12/30 00:26:21 nia Exp $

stdlib.h needed for rand()

--- src/randnum.c.orig	1997-12-10 01:56:00.000000000 +0000
+++ src/randnum.c
@@ -9,6 +9,7 @@
 */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <sys/time.h>
 #include "randnum.h"
 
