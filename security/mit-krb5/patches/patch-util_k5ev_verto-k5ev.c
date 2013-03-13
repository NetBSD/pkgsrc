$NetBSD: patch-util_k5ev_verto-k5ev.c,v 1.2 2013/03/13 12:35:40 adam Exp $

Fix include file path

--- util/k5ev/verto-k5ev.c.orig	2013-03-02 01:05:38.000000000 +0000
+++ util/k5ev/verto-k5ev.c
@@ -34,7 +34,7 @@
 
 #include "verto-k5ev.h"
 #include <verto-module.h>
-#include "rename.h"
+#include "gssrpc/rename.h"
 #include "autoconf.h"
 #define EV_STANDALONE 1
 /* Avoid using clock_gettime, which would create a dependency on librt. */
