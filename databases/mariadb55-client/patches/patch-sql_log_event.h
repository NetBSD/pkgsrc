$NetBSD: patch-sql_log_event.h,v 1.1 2015/04/16 20:20:15 ryoon Exp $

Portability: include <bstring.h> if exists.

--- sql/log_event.h.orig	2015-02-13 12:07:04.000000000 +0000
+++ sql/log_event.h
@@ -28,6 +28,10 @@
 #ifndef _log_event_h
 #define _log_event_h
 
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bzero() */
+#endif
+
 #if defined(USE_PRAGMA_INTERFACE) && defined(MYSQL_SERVER)
 #pragma interface			/* gcc class implementation */
 #endif
