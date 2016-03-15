$NetBSD: patch-util_k5ev_verto-k5ev.c,v 1.3 2016/03/15 15:16:39 tez Exp $

Fix include file path

--- util/verto/verto-k5ev.c.orig	2016-02-29 19:50:13.000000000 +0000
+++ util/verto/verto-k5ev.c
@@ -35,7 +35,7 @@
 
 #include <verto.h>
 #include <verto-module.h>
-#include "rename.h"
+#include "gssrpc/rename.h"
 #define EV_STANDALONE 1
 /* Avoid using clock_gettime, which would create a dependency on librt. */
 #define EV_USE_MONOTONIC 0
