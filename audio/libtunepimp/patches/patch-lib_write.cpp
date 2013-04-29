$NetBSD: patch-lib_write.cpp,v 1.1 2013/04/29 21:31:09 joerg Exp $

--- lib/write.cpp.orig	2013-04-28 12:27:41.000000000 +0000
+++ lib/write.cpp
@@ -35,6 +35,7 @@
 #  include <sys/stat.h>
 #  include <sys/types.h>
 #  include <fcntl.h>
+#  include <stdlib.h>
 #  if defined(__APPLE__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #    include <sys/param.h>
 #    include <sys/mount.h>
