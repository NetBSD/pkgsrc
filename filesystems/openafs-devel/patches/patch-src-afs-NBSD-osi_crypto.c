$NetBSD: patch-src-afs-NBSD-osi_crypto.c,v 1.1 2012/08/30 17:37:55 jakllsch Exp $

--- src/afs/NBSD/osi_crypto.c.orig	2012-04-22 23:40:23.000000000 -0400
+++ src/afs/NBSD/osi_crypto.c	2012-04-30 16:48:16.000000000 -0400
@@ -25,10 +25,19 @@
 #include <afsconfig.h>
 #include "afs/param.h"
 
+#ifdef AFS_NBSD70_ENV 
+#include <sys/cprng.h>
+#else
 #include <sys/rnd.h>
+#endif
+
 
 int
 osi_readRandom(void *data, afs_size_t len) {
+#ifdef AFS_NBSD70_ENV 
+    cprng_fast(data, len);
+#else
     rnd_extract_data(data, len, RND_EXTRACT_ANY);
+#endif
     return 0;
 }
