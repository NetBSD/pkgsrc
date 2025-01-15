$NetBSD: patch-src_programs_pkttyagent.c,v 1.4 2025/01/15 08:41:38 adam Exp $

Avoid %m usage in printf.

--- src/programs/pkttyagent.c.orig	2024-08-08 13:12:35.000000000 +0000
+++ src/programs/pkttyagent.c
@@ -20,6 +20,7 @@
  */
 
 #include <stdio.h>
+#include <errno.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <termios.h>
@@ -256,7 +257,7 @@ main (int argc, char *argv[])
     {
       if (close (opt_notify_fd) != 0)
         {
-          g_printerr ("Error closing notify-fd %d: %m\n", opt_notify_fd);
+          g_printerr ("Error closing notify-fd %d: %s\n", opt_notify_fd, g_strerror(errno));
           goto out;
         }
     }
