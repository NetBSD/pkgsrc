$NetBSD: patch-filetype_oniguruma_src_regposerr.c,v 1.1 2025/11/13 22:28:18 wiz Exp $

Check for config.h before including it.

--- filetype/oniguruma/src/regposerr.c.orig	2025-11-13 22:03:53.758831992 +0000
+++ filetype/oniguruma/src/regposerr.c
@@ -34,7 +34,9 @@
 #define ONIGURUMA_EXPORT
 #endif
 
+#ifdef HAVE_CONFIG_H
 #include "config.h"
+#endif
 #include "onigposix.h"
 
 #undef regex_t
