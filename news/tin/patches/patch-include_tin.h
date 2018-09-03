$NetBSD: patch-include_tin.h,v 1.1 2018/09/03 09:39:27 wiz Exp $

Use system libcanlock.

--- include/tin.h.orig	2017-12-08 07:52:23.000000000 +0000
+++ include/tin.h
@@ -2366,7 +2366,7 @@ extern struct tm *localtime(time_t *);
 
 /* libcanlock */
 #ifdef USE_CANLOCK
-#	include "../libcanlock/include/canlock.h"
+#	include <libcanlock-3/canlock.h>
 #endif /* USE_CANLOCK */
 
 /* gsasl */
