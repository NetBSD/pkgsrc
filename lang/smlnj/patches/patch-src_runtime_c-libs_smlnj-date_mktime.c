$NetBSD: patch-src_runtime_c-libs_smlnj-date_mktime.c,v 1.1 2016/07/03 19:35:13 dholland Exp $

Use standard headers.
Be explicit about truncating times, and avoid compiler warning.

--- src/runtime/c-libs/smlnj-date/mktime.c~	2007-06-01 16:19:33.000000000 +0000
+++ src/runtime/c-libs/smlnj-date/mktime.c
@@ -3,6 +3,8 @@
  * COPYRIGHT (c) 1995 AT&T Bell Laboratories.
  */
 
+#include <string.h>
+#include <stdint.h>
 #include <time.h>
 #include "ml-base.h"
 #include "ml-c.h"
@@ -40,8 +41,11 @@ ml_val_t _ml_Date_mktime (ml_state_t *ms
     }
     else {
 	ml_val_t	res;
+	/* XXX y2038 */
+	int32_t tt;
 
-	INT32_ALLOC(msp, res, t);
+	tt = t;
+	INT32_ALLOC(msp, res, tt);
 	return res;
     }
 
