$NetBSD: patch-src_libs3decoder_libcfg_s3__cfg__convert.c,v 1.1 2014/09/05 10:13:21 fhajny Exp $

Only use libbsd on Linux.
--- src/libs3decoder/libcfg/s3_cfg_convert.c.orig	2008-12-31 18:27:55.000000000 +0000
+++ src/libs3decoder/libcfg/s3_cfg_convert.c
@@ -1,5 +1,7 @@
 
+#if defined(__linux__)
 #include <libutil.h>
+#endif
 #include "s3_cfg.h"
 #include "fsg.h"
 
