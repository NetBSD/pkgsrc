$NetBSD: patch-tools_libxl_libxl_event.c,v 1.1 2021/04/18 12:31:26 bouyer Exp $

The SIGCHLD handler just writes to a pipe where the reader is the
same process. The idea is that this will cause poll(2) in the main
thread to exit with the reaper pipe readable, and do child cleanup here.

Unfortunably, is the child also has a write pipe back to the
parent (as e.g. with pygrub), the loop in afterpoll_internal() may see the
POLLHUP event on this pipe before the POLLIN even on the reaper pipe, and
this will be considered as an error (from e.g. pygrub).

work around by filtering POLLHUP events here

--- tools/libs/light/libxl_event.c.orig	2020-12-08 15:28:31.000000000 +0100
+++ tools/libs/light/libxl_event.c	2020-12-09 16:00:48.840221028 +0100
@@ -1443,7 +1443,7 @@
 
             revents = afterpoll_check_fd(poller,fds,nfds,
                                          efd->fd,efd->events);
-            if (revents)
+            if (revents & ~POLLHUP)
                 goto found_fd_event;
         }
         /* no ordinary fd events, then */
