$NetBSD: patch-src_programs_pkttyagent.c,v 1.2 2018/04/29 05:14:37 wiz Exp $

Avoid %m usage in printf.

--- src/programs/pkttyagent.c.orig	2018-04-03 18:16:17.000000000 +0000
+++ src/programs/pkttyagent.c
@@ -24,6 +24,7 @@
 #endif
 
 #include <stdio.h>
+#include <errno.h>
 #include <stdlib.h>
 #include <glib/gi18n.h>
 #include <polkit/polkit.h>
@@ -206,7 +207,7 @@ main (int argc, char *argv[])
     {
       if (close (opt_notify_fd) != 0)
         {
-          g_printerr ("Error closing notify-fd %d: %m\n", opt_notify_fd);
+          g_printerr ("Error closing notify-fd %d: %s\n", opt_notify_fd, g_strerror(errno));
           goto out;
         }
     }
