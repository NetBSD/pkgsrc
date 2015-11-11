$NetBSD: patch-backend_pieusb__buffer.c,v 1.3 2015/11/11 12:40:03 wiz Exp $

Remove unportable header inclusion.
XXX: should be fixed better, hope upstream does that.
https://alioth.debian.org/tracker/index.php?func=detail&aid=315209&group_id=30186&atid=410366

--- backend/pieusb_buffer.c.orig	2015-09-01 00:31:33.000000000 +0000
+++ backend/pieusb_buffer.c
@@ -100,15 +100,8 @@
 #include <stdio.h>
 #include <fcntl.h>
 #include <sys/mman.h>
-#include <endian.h>
 
-/* When creating the release backend, make complains about unresolved external
- * le16toh, although it finds the include <endian.h> */
-#if __BYTE_ORDER == __LITTLE_ENDIAN
- #define le16toh(x) (x)
-#else
- #define le16toh(x) __bswap_16 (x)
-#endif
+#include "byteorder.h"
 
 static void buffer_update_read_index(struct Pieusb_Read_Buffer* buffer, int increment);
 
