$NetBSD: patch-src_system_ByteOrder.hxx,v 1.2 2014/08/21 12:14:16 wiz Exp $

<endian.h> is a non-standard header that only Linux provides.

http://bugs.musicpd.org/view.php?id=4060

--- src/system/ByteOrder.hxx.orig	2014-05-15 23:46:49.000000000 +0000
+++ src/system/ByteOrder.hxx
@@ -40,8 +40,18 @@
 /* well-known big-endian */
 #  define IS_LITTLE_ENDIAN false
 #  define IS_BIG_ENDIAN true
+#elif defined(__APPLE__)
+/* generic compile-time check for MacOS */
+#  include <machine/endian.h>
+#  if BYTE_ORDER == LITTLE_ENDIAN
+#    define IS_LITTLE_ENDIAN true
+#    define IS_BIG_ENDIAN false
+#  else
+#    define IS_LITTLE_ENDIAN false
+#    define IS_BIG_ENDIAN true
+#  endif
 #else
-/* generic compile-time check */
+/* generic compile-time check for Linux */
 #  include <endian.h>
 #  if __BYTE_ORDER == __LITTLE_ENDIAN
 #    define IS_LITTLE_ENDIAN true
