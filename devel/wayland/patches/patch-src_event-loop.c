$NetBSD: patch-src_event-loop.c,v 1.2 2020/01/05 19:30:48 nia Exp $

https://lists.freedesktop.org/archives/wayland-devel/2019-February/040024.html

--- src/event-loop.c.orig	2019-03-21 00:55:25.000000000 +0000
+++ src/event-loop.c
@@ -23,6 +23,8 @@
  * SOFTWARE.
  */
 
+#include "config.h"
+#ifdef HAVE_SYS_EPOLL_H
 #include <stddef.h>
 #include <stdio.h>
 #include <errno.h>
@@ -702,3 +704,4 @@ wl_event_loop_get_destroy_listener(struc
 {
 	return wl_signal_get(&loop->destroy_signal, notify);
 }
+#endif /* HAVE_SYS_EPOLL_H */
