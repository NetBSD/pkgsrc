$NetBSD: patch-lib_user_util.c,v 1.1.2.2 2016/05/23 05:09:17 bsiegert Exp $

--- lib/user/util.c.orig	2016-05-06 15:59:45.000000000 +0000
+++ lib/user/util.c
@@ -319,7 +319,7 @@ UtilBacktraceToBufferCallback(struct _Un
     */
    if (cfa >= data->basePtr) {
       if (data->len) {
-         *data->buffer++ = _Unwind_GetIP(ctx);
+         *data->buffer++ = (uintptr_t)_Unwind_GetIP(ctx);
          data->len--;
       } else {
          return _URC_END_OF_STACK;
