$NetBSD: patch-src_core_ext_transport_chttp2_transport_flow__control.c,v 1.1 2017/10/23 15:48:04 minskim Exp $

Include limits.h to use INT_MAX.

--- src/core/ext/transport/chttp2/transport/flow_control.c.orig	2017-10-19 02:10:38.000000000 +0000
+++ src/core/ext/transport/chttp2/transport/flow_control.c
@@ -18,6 +18,7 @@
 
 #include "src/core/ext/transport/chttp2/transport/internal.h"
 
+#include <limits.h>
 #include <math.h>
 #include <string.h>
 
