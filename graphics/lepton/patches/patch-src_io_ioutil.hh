$NetBSD: patch-src_io_ioutil.hh,v 1.1 2016/08/26 17:20:54 joerg Exp $

--- src/io/ioutil.hh.orig	2016-08-26 13:44:46.748006379 +0000
+++ src/io/ioutil.hh
@@ -2,7 +2,7 @@
 #define _SIRIKIATA_IO_UTIL_HH_
 #ifndef _WIN32
 #include <unistd.h>
-#include <sys/errno.h>
+#include <errno.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #endif
