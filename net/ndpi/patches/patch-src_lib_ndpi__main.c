$NetBSD: patch-src_lib_ndpi__main.c,v 1.1 2018/10/18 16:24:29 adam Exp $

Fix build (https://github.com/ntop/nDPI/issues/600).

--- src/lib/ndpi_main.c.orig	2018-10-08 10:11:40.000000000 +0000
+++ src/lib/ndpi_main.c
@@ -43,9 +43,7 @@
 
 #include "ndpi_content_match.c.inc"
 #include "third_party/include/ndpi_patricia.h"
-#include "third_party/src/ndpi_patricia.c"
 #include "third_party/include/hash.h"
-#include "third_party/src/hash.c"
 
 #ifdef HAVE_HYPERSCAN
 #include <hs/hs.h>
