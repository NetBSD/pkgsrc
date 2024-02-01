$NetBSD: patch-src_conf_nwfilter__params.h,v 1.1 2024/02/01 09:01:06 wiz Exp $

Fix build with libxml2 2.12.

--- src/conf/nwfilter_params.h.orig	2024-02-01 08:59:49.292522483 +0000
+++ src/conf/nwfilter_params.h
@@ -26,6 +26,7 @@
 # include "virhash.h"
 # include "virbuffer.h"
 # include "virmacaddr.h"
+# include <libxml/parser.h>
 
 typedef enum {
     NWFILTER_VALUE_TYPE_SIMPLE,
