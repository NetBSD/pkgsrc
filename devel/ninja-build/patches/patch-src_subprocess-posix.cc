$NetBSD: patch-src_subprocess-posix.cc,v 1.1 2017/02/09 00:24:23 joerg Exp $

For pselect.

--- src/subprocess-posix.cc.orig	2017-02-08 21:59:55.779788481 +0000
+++ src/subprocess-posix.cc
@@ -14,6 +14,7 @@
 
 #include "subprocess.h"
 
+#include <sys/select.h>
 #include <assert.h>
 #include <errno.h>
 #include <fcntl.h>
