$NetBSD: patch-sql_log_event.h,v 1.1 2013/02/13 21:00:07 adam Exp $

* Portability: include <bstring.h> if exists.

--- sql/log_event.h.orig	2013-01-22 16:54:50.000000000 +0000
+++ sql/log_event.h
@@ -28,6 +28,10 @@
 #ifndef _log_event_h
 #define _log_event_h
 
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bzero() */
+#endif
+
 #include <my_bitmap.h>
 #include "rpl_constants.h"
 
