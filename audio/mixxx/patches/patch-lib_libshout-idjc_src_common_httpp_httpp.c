$NetBSD: patch-lib_libshout-idjc_src_common_httpp_httpp.c,v 1.1 2025/10/12 09:38:51 mrg Exp $

Include <strings.h> for strcasecmp().


--- lib/libshout-idjc/src/common/httpp/httpp.c.orig	2021-09-29 06:23:02.000000000 -0700
+++ lib/libshout-idjc/src/common/httpp/httpp.c	2025-10-12 02:26:05.022084395 -0700
@@ -33,6 +33,7 @@
 
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <ctype.h>
 
 #include <avl/avl.h>
