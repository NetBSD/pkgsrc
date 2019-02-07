$NetBSD: patch-src_kal.cc,v 1.1 2019/02/07 14:03:22 tnn Exp $

for basename(3)

--- src/kal.cc.orig	2016-07-04 03:55:59.000000000 +0000
+++ src/kal.cc
@@ -48,9 +48,7 @@
 #include <unistd.h>
 #include <sys/time.h>
 #endif
-#ifdef D_HOST_OSX
 #include <libgen.h>
-#endif /* D_HOST_OSX */
 #include <string.h>
 
 #include <errno.h>
