$NetBSD: patch-screens.c,v 1.1 2025/09/29 20:44:50 mrg Exp $

--- screens.c.orig	1999-06-30 11:25:02.000000000 -0700
+++ screens.c	2025-09-26 12:45:30.940708475 -0700
@@ -37,6 +37,7 @@
    /* Misc. */
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #if defined HALFSIZE
 #define MULT 0.5
