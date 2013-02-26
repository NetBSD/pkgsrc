$NetBSD: patch-better.c,v 1.1 2013/02/26 11:25:12 joerg Exp $

--- better.c.orig	2013-02-25 20:36:11.000000000 +0000
+++ better.c
@@ -12,11 +12,13 @@
 */
 
 #include <math.h>
+#include <limits.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include "netmaze.h"
 #include "better.h"
 
-#define BIGGEST			/* groesster long-wert */
+#define BIGGEST		LONG_MAX	/* groesster long-wert */
 #define NERVOUS 50000000 	/* ab hier sucht BB sein Opfer */
 #define TODESRADIUS1 7000000
 #define TODESRADIUS 15000000   
