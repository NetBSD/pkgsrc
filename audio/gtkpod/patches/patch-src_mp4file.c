$NetBSD: patch-src_mp4file.c,v 1.1 2012/02/15 21:42:09 hans Exp $

--- src/mp4file.c.orig	2010-04-26 21:30:52.000000000 +0200
+++ src/mp4file.c	2012-01-18 01:00:11.494883587 +0100
@@ -35,6 +35,11 @@
 #  include <endian.h> /* for be32toh () */
 #endif
 
+#ifdef __sun
+#  include <sys/byteorder.h>
+#  define be32toh BE_32
+#endif
+
 #include "charset.h"
 #include "itdb.h"
 #include "misc.h"
