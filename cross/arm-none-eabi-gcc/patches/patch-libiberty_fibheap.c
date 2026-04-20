$NetBSD: patch-libiberty_fibheap.c,v 1.1 2026/04/20 03:49:24 js Exp $

For some reason, HAVE_LIMITS_H is not defined on Linux and makes it fail.

--- libiberty/fibheap.c.orig	2025-06-15 13:06:53.573537761 +0000
+++ libiberty/fibheap.c
@@ -22,9 +22,7 @@ Boston, MA 02110-1301, USA.  */
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
-#ifdef HAVE_LIMITS_H
 #include <limits.h>
-#endif
 #ifdef HAVE_STDLIB_H
 #include <stdlib.h>
 #endif
