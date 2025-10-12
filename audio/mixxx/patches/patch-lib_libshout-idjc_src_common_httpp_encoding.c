$NetBSD: patch-lib_libshout-idjc_src_common_httpp_encoding.c,v 1.1 2025/10/12 09:38:51 mrg Exp $

Include <strings.h> for strcasecmp().


--- lib/libshout-idjc/src/common/httpp/encoding.c.orig	2021-09-29 06:23:02.000000000 -0700
+++ lib/libshout-idjc/src/common/httpp/encoding.c	2025-10-12 02:25:56.191075240 -0700
@@ -28,6 +28,7 @@
 
 #include <sys/types.h>
 #include <string.h>
+#include <strings.h>
 #include <stdlib.h>
 #include <stdio.h>
 
