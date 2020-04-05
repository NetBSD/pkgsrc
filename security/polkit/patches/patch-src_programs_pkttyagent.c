$NetBSD: patch-src_programs_pkttyagent.c,v 1.3 2020/04/05 06:14:08 wiz Exp $

Avoid %m usage in printf.

--- src/programs/pkttyagent.c.orig	2019-04-02 11:20:42.000000000 +0000
+++ src/programs/pkttyagent.c
@@ -24,6 +24,7 @@
 #endif
 
 #include <stdio.h>
+#include <errno.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <termios.h>
@@ -242,7 +243,7 @@ main (int argc, char *argv[])
     {
       if (close (opt_notify_fd) != 0)
         {
-          g_printerr ("Error closing notify-fd %d: %m\n", opt_notify_fd);
+          g_printerr ("Error closing notify-fd %d: %s\n", opt_notify_fd, g_strerror(errno));
           goto out;
         }
     }
