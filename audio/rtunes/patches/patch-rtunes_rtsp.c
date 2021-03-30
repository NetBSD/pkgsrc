$NetBSD: patch-rtunes_rtsp.c,v 1.1 2021/03/30 12:01:04 nia Exp $

Merge fixes from https://github.com/erincandescent/rtunes

--- rtunes/rtsp.c.orig	2009-06-27 10:10:32.000000000 +0000
+++ rtunes/rtsp.c
@@ -19,15 +19,14 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <openssl/rand.h>
 
 #include "config.h"
 #include "extern.h"
 #include "proto.h"
 
 #ifdef __linux__
-#include "../libbsd/strlcpy.h"
-#include "../libbsd/strlcat.h"
-#include "../libbsd/arc4random.h"
+#include "bsd/string.h"
 #endif
 
 /* global vars local */
@@ -48,7 +47,7 @@ rtsp_generate_sid(char *buf, int len)
 	int	i = 0;
 
 	while (i < 1000000000)
-		i = arc4random();
+		RAND_bytes((unsigned char*) &i, sizeof(i));
 
 	snprintf(buf, len, "%d", i);
 
