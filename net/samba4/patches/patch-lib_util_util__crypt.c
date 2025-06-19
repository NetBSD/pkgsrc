$NetBSD: patch-lib_util_util__crypt.c,v 1.2 2025/06/19 02:08:47 gutteridge Exp $

Do not include <crypt.h> unconditionally.

Account for platforms that don't define ENOTRECOVERABLE, like NetBSD
before 10.0.

--- lib/util/util_crypt.c.orig	2025-02-17 15:48:20.606155400 +0000
+++ lib/util/util_crypt.c
@@ -2,7 +2,9 @@
 #include "data_blob.h"
 #include "discard.h"
 #include <talloc.h>
+#ifdef HAVE_CRYPT_H
 #include <crypt.h>
+#endif
 #include "util_crypt.h"
 
 
@@ -62,7 +64,11 @@ static int crypt_as_best_we_can(TALLOC_C
 	if (hash == NULL || hash[0] == '*') {
 		if (ret == 0) {
 			/* this is annoying */
+#ifdef ENOTRECOVERABLE
 			ret = ENOTRECOVERABLE;
+#else
+			ret = ENOSYS;
+#endif
 		}
 	}
 	if (ret != 0) {
@@ -107,7 +113,11 @@ char *talloc_crypt_errstring(TALLOC_CTX 
 			mem_ctx,
 			"Password exceeds maximum length allowed for crypt() hashing");
 	}
+#ifdef ENOTRECOVERABLE
 	if (error == ENOTRECOVERABLE) {
+#else
+	if (error == ENOSYS) {
+#endif
 		/* probably weird RHEL7 crypt, see crypt_as_best_we_can() */
 		goto unknown;
 	}
