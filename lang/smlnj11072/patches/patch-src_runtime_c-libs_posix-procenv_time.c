$NetBSD: patch-src_runtime_c-libs_posix-procenv_time.c,v 1.1 2016/07/03 19:35:36 dholland Exp $

Be explicit about truncating times, and avoid compiler warning.

--- src/runtime/c-libs/posix-procenv/time.c~	2000-06-01 18:34:03.000000000 +0000
+++ src/runtime/c-libs/posix-procenv/time.c
@@ -3,6 +3,7 @@
  * COPYRIGHT (c) 1995 by AT&T Bell Laboratories.
  */
 
+#include <stdint.h>
 #include "ml-base.h"
 #include "ml-values.h"
 #include "ml-objects.h"
@@ -17,11 +18,14 @@
 ml_val_t _ml_P_ProcEnv_time (ml_state_t *msp, ml_val_t arg)
 {
     time_t      t;
+    int32_t	tt;
     ml_val_t	res;
 
     t = time (NIL(time_t*));
 
-    INT32_ALLOC(msp, res, t);
+    /* XXX y2038 */
+    tt = t;
+    INT32_ALLOC(msp, res, tt);
     return res;
 
 } /* end of _ml_P_ProcEnv_time */
