$NetBSD: patch-image_utils.c,v 1.1 2012/10/15 22:48:02 drochner Exp $

--- image_utils.c.orig	2012-10-15 19:04:54.000000000 +0000
+++ image_utils.c
@@ -32,17 +32,25 @@
 #include <unistd.h>
 #include <setjmp.h>
 #include <jpeglib.h>
+#ifdef __NetBSD__
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 
 #include "upnpreplyparse.h"
 #include "image_utils.h"
 #include "log.h"
 
+#ifdef __NetBSD__
+#define SWAP16(w) htobe16(w)
+#else
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 # define SWAP16(w) ( (((w) >> 8) & 0x00ff) | (((w) << 8) & 0xff00) )
 #else
 # define SWAP16(w) (w)
 #endif
+#endif /* NetBSD */
 
 #define JPEG_QUALITY  96
 
