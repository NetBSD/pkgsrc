$NetBSD: patch-bus_dir-watch-kqueue.c,v 1.2 2014/06/14 21:52:56 wiz Exp $

* For platforms missing O_CLOEXEC
https://bugs.freedesktop.org/show_bug.cgi?id=77032

--- bus/dir-watch-kqueue.c.orig	2014-01-25 12:39:24.000000000 +0000
+++ bus/dir-watch-kqueue.c
@@ -202,6 +202,9 @@ bus_set_watched_dirs (BusContext *contex
   DBusList *link;
   int i, j, fd;
   struct kevent ev;
+#ifdef O_CLOEXEC
+  dbus_bool_t cloexec_done = 0;
+#endif
 
   if (!_init_kqueue (context))
     goto out;
@@ -259,7 +262,15 @@ bus_set_watched_dirs (BusContext *contex
           /* FIXME - less lame error handling for failing to add a watch;
            * we may need to sleep.
            */
+#ifdef O_CLOEXEC
           fd = open (new_dirs[i], O_RDONLY | O_CLOEXEC);
+          cloexec_done = (fd >= 0);
+
+          if (fd < 0 && errno == EINVAL)
+#endif
+            {
+              fd = open (new_dirs[i], O_RDONLY);
+            }
           if (fd < 0)
             {
               if (errno != ENOENT)
@@ -274,6 +285,12 @@ bus_set_watched_dirs (BusContext *contex
                   continue;
                 }
             }
+#ifdef O_CLOEXEC
+          if (!cloexec_done)
+#endif
+            {
+              _dbus_fd_set_close_on_exec (fd);
+            }
 
           EV_SET (&ev, fd, EVFILT_VNODE, EV_ADD | EV_ENABLE | EV_CLEAR,
                   NOTE_DELETE | NOTE_EXTEND | NOTE_WRITE | NOTE_RENAME, 0, 0);
