$NetBSD: patch-sql_log__event.h,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

* Portability: include <bstring.h> if exists.

--- sql/log_event.h.orig	2021-09-14 09:08:08.000000000 +0000
+++ sql/log_event.h
@@ -35,6 +35,10 @@
 #ifndef _log_event_h
 #define _log_event_h
 
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bzero() */
+#endif
+
 #include "my_global.h"
 #include "my_bitmap.h"               // MY_BITMAP
 #include "binary_log.h"              // binary_log
