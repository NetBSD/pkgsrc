$NetBSD: patch-backend_pieusb__buffer.c,v 1.2 2015/10/27 11:29:35 wiz Exp $

Remove unportable header inclusion.
XXX: should be fixed better, hope upstream does that.
https://alioth.debian.org/tracker/index.php?func=detail&aid=315209&group_id=30186&atid=410366

--- backend/pieusb_buffer.c.orig	2015-09-01 00:31:33.000000000 +0000
+++ backend/pieusb_buffer.c
@@ -100,7 +100,9 @@
 #include <stdio.h>
 #include <fcntl.h>
 #include <sys/mman.h>
+#ifdef HAVE_ENDIAN_H
 #include <endian.h>
+#endif
 
 /* When creating the release backend, make complains about unresolved external
  * le16toh, although it finds the include <endian.h> */
