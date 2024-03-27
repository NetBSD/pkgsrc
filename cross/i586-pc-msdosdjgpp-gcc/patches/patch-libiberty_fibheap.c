$NetBSD: patch-libiberty_fibheap.c,v 1.1 2024/03/27 14:38:33 js Exp $

This is very weird. When replacing the #include with an #error, it does
trigger. But when using the #include inside the #ifdef HAVE_LIMITS_H, LONG_MIN
isn't defined. I suspect this file is compiled twice, with two different
config.h files.

--- libiberty/fibheap.c.orig	2024-03-27 12:02:01.332671019 +0000
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
@@ -34,7 +32,6 @@ Boston, MA 02110-1301, USA.  */
 #include "libiberty.h"
 #include "fibheap.h"
 
-
 #define FIBHEAPKEY_MIN	LONG_MIN
 
 static void fibheap_ins_root (fibheap_t, fibnode_t);
