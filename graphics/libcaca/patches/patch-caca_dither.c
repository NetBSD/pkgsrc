$NetBSD: patch-caca_dither.c,v 1.1 2017/12/03 03:57:31 maya Exp $

Assume POSIX style endian.h (POSIX introduced this in 2011)
Provide fallback definitions for the older code that has existed before.

--- caca/dither.c.orig	2010-02-15 23:45:36.000000000 +0000
+++ caca/dither.c
@@ -19,6 +19,12 @@
 #if !defined(__KERNEL__)
 #   if defined(HAVE_ENDIAN_H)
 #       include <endian.h>
+#       ifndef BYTE_ORDER
+#           define BYTE_ORDER __BYTE_ORDER
+#       endif
+#       ifndef BIG_ENDIAN
+#           define BIG_ENDIAN __BIG_ENDIAN
+#       endif
 #   endif
 #   include <stdio.h>
 #   include <stdlib.h>
@@ -1324,7 +1330,7 @@ static void get_rgba_default(caca_dither
         case 3:
         {
 #if defined(HAVE_ENDIAN_H)
-            if(__BYTE_ORDER == __BIG_ENDIAN)
+            if(BYTE_ORDER == BIG_ENDIAN)
 #else
             /* This is compile-time optimised with at least -O1 or -Os */
             uint32_t const tmp = 0x12345678;
