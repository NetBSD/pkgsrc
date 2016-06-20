$NetBSD: patch-libs_pbd_fpu.cc,v 1.1 2016/06/20 08:17:43 kamil Exp $

There are problems with C++11 heavy code on NetBSD when building against _XOPEN_SOURCE.

--- libs/pbd/fpu.cc.orig	2016-02-19 01:28:56.000000000 +0000
+++ libs/pbd/fpu.cc
@@ -19,7 +19,9 @@
 
 #include "libpbd-config.h"
 
+#ifndef __NetBSD__
 #define _XOPEN_SOURCE 600
+#endif
 #include <cstring> // for memset
 #include <cstdlib>
 #include <stdint.h>
