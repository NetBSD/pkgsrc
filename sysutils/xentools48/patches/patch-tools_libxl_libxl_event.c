$NetBSD: patch-tools_libxl_libxl_event.c,v 1.1 2017/03/30 09:15:10 bouyer Exp $

The SIGCHLD handler just writes to a pipe where the reader is the
same process. The idea is that this will cause poll(2) in the main
thread to exit with the reaper pipe readable, and do child cleanup here.

Unfortunably, is the child also has a write pipe back to the
parent (as e.g. with pygrub), the loop in afterpoll_internal() may see the
POLLHUP event on this pipe before the POLLIN even on the reaper pipe, and
this will be considered as an error (from e.g. pygrub).

work around by filtering POLLHUP events here

--- tools/libxl/libxl_event.c.orig	2016-12-20 16:01:30.000000000 +0100
+++ tools/libxl/libxl_event.c	2016-12-20 17:28:52.000000000 +0100
@@ -1261,7 +1261,7 @@
 
             revents = afterpoll_check_fd(poller,fds,nfds,
                                          efd->fd,efd->events);
-            if (revents)
+            if (revents & ~POLLHUP)
                 goto found_fd_event;
         }
         /* no ordinary fd events, then */
