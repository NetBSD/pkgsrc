$NetBSD: patch-rpc2-src_rpc2b.c,v 1.1 2015/01/23 14:31:38 hauke Exp $

SunOS wants the header imported explicitely.

--- rpc2-src/rpc2b.c.orig	2010-03-22 19:18:30.000000000 +0000
+++ rpc2-src/rpc2b.c
@@ -60,6 +60,7 @@ Pittsburgh, PA.
 #include <errno.h>
 #include <assert.h>
 #include <sys/file.h>
+#include <fcntl.h>
 
 #include <rpc2/secure.h>
 #include "rpc2.private.h"
