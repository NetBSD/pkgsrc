$NetBSD: patch-ext_io_event_selector_selector.h,v 1.1 2024/02/03 15:22:55 taca Exp $

selector.c require WNOHANG from <sys/wait.h>.

--- ext/io/event/selector/selector.h.orig	2024-01-04 07:49:41.079012504 +0000
+++ ext/io/event/selector/selector.h
@@ -34,6 +34,7 @@
 #endif
 
 #include <time.h>
+#include <sys/wait.h>
 
 enum IO_Event {
 	IO_EVENT_READABLE = 1,
