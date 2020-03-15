$NetBSD: patch-src_event-loop.c,v 1.3 2020/03/15 16:03:26 nia Exp $

https://lists.freedesktop.org/archives/wayland-devel/2019-February/040024.html

--- src/event-loop.c.orig	2020-02-11 23:46:03.000000000 +0000
+++ src/event-loop.c
@@ -23,6 +23,8 @@
  * SOFTWARE.
  */
 
+#include "config.h"
+#ifdef HAVE_SYS_EPOLL_H
 #include <assert.h>
 #include <stddef.h>
 #include <stdio.h>
@@ -1088,3 +1090,4 @@ wl_event_loop_get_destroy_listener(struc
 {
 	return wl_signal_get(&loop->destroy_signal, notify);
 }
+#endif /* HAVE_SYS_EPOLL_H */
