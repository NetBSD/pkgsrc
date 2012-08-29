$NetBSD: patch-src_iop_watermark.c,v 1.1 2012/08/29 16:26:51 wiz Exp $

Direct inclusion of this header is deprecated.

--- src/iop/watermark.c.orig	2012-07-21 10:44:08.000000000 +0000
+++ src/iop/watermark.c
@@ -38,7 +38,6 @@
 #include <inttypes.h>
 
 #include <librsvg/rsvg.h>
-#include <librsvg/rsvg-cairo.h>
 
 #include "common/metadata.h"
 #include "common/utility.h"
