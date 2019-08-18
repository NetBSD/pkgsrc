$NetBSD: patch-src_event-loop.c,v 1.1 2019/08/18 16:05:12 nia Exp $

https://lists.freedesktop.org/archives/wayland-devel/2019-February/040024.html

--- src/event-loop.c.orig	2019-03-21 00:55:25.000000000 +0000
+++ src/event-loop.c
@@ -22,7 +22,8 @@
  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  * SOFTWARE.
  */
-
+#include "config.h"
+#ifdef HAVE_SYS_EPOLL_H
 #include <stddef.h>
 #include <stdio.h>
 #include <errno.h>
@@ -35,9 +36,9 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <sys/epoll.h>
+#include <unistd.h>
 #include <sys/signalfd.h>
 #include <sys/timerfd.h>
-#include <unistd.h>
 #include "wayland-util.h"
 #include "wayland-private.h"
 #include "wayland-server-core.h"
@@ -702,3 +703,4 @@ wl_event_loop_get_destroy_listener(struc
 {
 	return wl_signal_get(&loop->destroy_signal, notify);
 }
+#endif /* HAVE_SYS_EPOLL_H */
