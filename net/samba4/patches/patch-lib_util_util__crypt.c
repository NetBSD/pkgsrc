$NetBSD: patch-lib_util_util__crypt.c,v 1.1 2025/06/04 14:43:09 taca Exp $

Do not include <crypt.h> unconditionally.

--- lib/util/util_crypt.c.orig	2025-06-04 00:59:55.724394893 +0000
+++ lib/util/util_crypt.c
@@ -2,7 +2,9 @@
 #include "data_blob.h"
 #include "discard.h"
 #include <talloc.h>
+#ifdef HAVE_CRYPT_H
 #include <crypt.h>
+#endif
 #include "util_crypt.h"
 
 
