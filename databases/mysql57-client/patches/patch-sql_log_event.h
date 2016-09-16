$NetBSD: patch-sql_log_event.h,v 1.1 2016/09/16 06:49:11 adam Exp $

* Portability: include <bstring.h> if exists.

--- sql/log_event.h.orig	2016-03-28 18:06:12.000000000 +0000
+++ sql/log_event.h
@@ -28,6 +28,10 @@
 #ifndef _log_event_h
 #define _log_event_h
 
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bzero() */
+#endif
+
 #include "my_global.h"
 #include "my_bitmap.h"               // MY_BITMAP
 #include "binary_log.h"              // binary_log
