$NetBSD: patch-lib_libshout-idjc_src_proto_http.c,v 1.1 2025/10/12 09:38:51 mrg Exp $

Include <strings.h> for strcasecmp().


--- lib/libshout-idjc/src/proto_http.c.orig	2021-09-29 06:23:02.000000000 -0700
+++ lib/libshout-idjc/src/proto_http.c	2025-10-12 02:26:23.717213398 -0700
@@ -28,6 +28,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 
 #include <shoutidjc/shout.h>
 #include "shout_private.h"
