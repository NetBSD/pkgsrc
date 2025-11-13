$NetBSD: patch-filetype_oniguruma_src_regenc.h,v 1.1 2025/11/13 22:28:18 wiz Exp $

Check for config.h before including it.

--- filetype/oniguruma/src/regenc.h.orig	2025-11-13 22:03:27.734779409 +0000
+++ filetype/oniguruma/src/regenc.h
@@ -33,7 +33,9 @@
 #define ONIGURUMA_EXPORT
 #endif
 
+#ifdef HAVE_CONFIG_H
 #include "config.h"
+#endif
 
 #ifndef ONIG_NO_STANDARD_C_HEADERS
 #include <stddef.h>
