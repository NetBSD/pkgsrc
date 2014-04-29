$NetBSD: patch-bus_dir-watch-kqueue.c,v 1.1 2014/04/29 10:18:54 obache Exp $

* For platforms missing O_CLOEXEC
https://bugs.freedesktop.org/show_bug.cgi?id=77032

--- bus/dir-watch-kqueue.c.orig	2014-01-06 16:02:19.000000000 +0000
+++ bus/dir-watch-kqueue.c
@@ -259,7 +259,15 @@ bus_set_watched_dirs (BusContext *contex
           /* FIXME - less lame error handling for failing to add a watch;
            * we may need to sleep.
            */
+#ifdef O_CLOEXEC
           fd = open (new_dirs[i], O_RDONLY | O_CLOEXEC);
+
+          if (fd < 0 && errno == EINVAL)
+#endif
+          {
+            fd = open (new_dirs[i], O_RDONLY);
+            _dbus_fd_set_close_on_exec (fd);
+          }
           if (fd < 0)
             {
               if (errno != ENOENT)
