$NetBSD: patch-logview_logview-utils.c,v 1.1 2018/02/06 10:39:46 jperkin Exp $

Set _XOPEN_SOURCE correctly.

--- logview/logview-utils.c.orig	2009-09-21 15:54:41.000000000 +0000
+++ logview/logview-utils.c
@@ -19,7 +19,9 @@
  * Foundation, Inc., 551 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
  */
 
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _XOPEN_SOURCE
+#endif
 #include <time.h>
 #include <string.h>
 #include <stdlib.h>
@@ -274,4 +276,4 @@ log_read_dates (const char **buffer_line
   days = g_slist_sort (days, days_compare);
 
   return days;
-}
\ No newline at end of file
+}
