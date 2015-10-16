$NetBSD: patch-gio_gtestdbus.c,v 1.1 2015/10/16 10:18:48 tnn Exp $

%m modifier is a GNU extension and not permitted in sprintf.

--- gio/gtestdbus.c.orig	2015-05-13 02:39:04.000000000 +0000
+++ gio/gtestdbus.c
@@ -25,6 +25,8 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <gstdio.h>
+#include <errno.h>
+#include <string.h> /* for strerror(3) */
 #ifdef G_OS_UNIX
 #include <unistd.h>
 #endif
@@ -243,14 +245,14 @@ watcher_init (void)
       /* fork a child to clean up when we are killed */
       if (pipe (pipe_fds) != 0)
         {
-          g_warning ("pipe() failed: %m");
+          g_warning ("pipe() failed: %s", strerror(errno));
           g_assert_not_reached ();
         }
 
       switch (fork ())
         {
         case -1:
-          g_warning ("fork() failed: %m");
+          g_warning ("fork() failed: %s", strerror(errno));
           g_assert_not_reached ();
           break;
 
