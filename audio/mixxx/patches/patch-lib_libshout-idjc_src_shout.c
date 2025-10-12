$NetBSD: patch-lib_libshout-idjc_src_shout.c,v 1.1 2025/10/12 09:38:51 mrg Exp $

Include <strings.h> for strcasecmp().


--- lib/libshout-idjc/src/shout.c.orig	2021-09-29 06:23:02.000000000 -0700
+++ lib/libshout-idjc/src/shout.c	2025-10-12 02:26:14.844270957 -0700
@@ -29,6 +29,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <errno.h>
 
 #include <shoutidjc/shout.h>
