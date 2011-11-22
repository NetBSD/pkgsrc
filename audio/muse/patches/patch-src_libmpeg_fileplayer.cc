$NetBSD: patch-src_libmpeg_fileplayer.cc,v 1.1 2011/11/22 20:50:54 wiz Exp $

iostream.h is deprecated.

--- src/libmpeg/fileplayer.cc.orig	2011-11-22 20:45:56.000000000 +0000
+++ src/libmpeg/fileplayer.cc
@@ -10,7 +10,7 @@
 #endif
 
 #include <string.h>
-#include <iostream.h>
+#include <iostream>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
