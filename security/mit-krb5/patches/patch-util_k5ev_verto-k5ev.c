$NetBSD: patch-util_k5ev_verto-k5ev.c,v 1.1 2012/07/16 19:12:33 adam Exp $

Fix include file path

--- util/k5ev/verto-k5ev.c.orig	2012-06-27 13:41:58.000000000 +0000
+++ util/k5ev/verto-k5ev.c
@@ -34,7 +34,7 @@
 
 #include "verto-k5ev.h"
 #include <verto-module.h>
-#include "rename.h"
+#include "gssrpc/rename.h"
 #include "autoconf.h"
 #define EV_STANDALONE 1
 /* Avoids using clock_gettime; we probably shouldn't have to do this. */
