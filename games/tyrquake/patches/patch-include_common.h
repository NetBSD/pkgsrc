$NetBSD: patch-include_common.h,v 1.1 2024/06/06 17:33:14 ktnb Exp $

NetBSD has bswap in stdlib which conflicts with upstream's
definitions. Using the upstream definitions causes a conflict
throughout the rest of the program.

--- include/common.h.orig	2022-09-06 10:23:53.000000000 +0000
+++ include/common.h
@@ -24,6 +24,9 @@ Foundation, Inc., 51 Franklin Street, Fi
 
 #include <stdarg.h>
 #include <stdio.h>
+#ifdef __NetBSD__
+#include <stdlib.h>
+#endif
 
 #include "qtypes.h"
 #include "shell.h"
@@ -105,6 +108,7 @@ void InsertLinkAfter(link_t *l, link_t *
  * ========================================================================
  */
 
+#ifndef __NetBSD__
 static inline short bswap16(short s)
 {
     return ((s & 255) << 8) | ((s >> 8) & 255);
@@ -117,6 +121,7 @@ static inline int bswap32(int l)
         | (((l >> 16) & 255) <<  8)
         | (((l >> 24) & 255) <<  0);
 }
+#endif
 
 #ifdef __BIG_ENDIAN__
 static inline short BigShort(short s) { return s; }
