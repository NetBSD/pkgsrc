$NetBSD: patch-lib_driver_logging.c,v 1.1 2019/04/29 17:22:04 adam Exp $

Do not exit() on error.

--- lib/driver/logging.c.orig	2018-08-12 16:33:48.000000000 +0000
+++ lib/driver/logging.c
@@ -49,7 +49,6 @@ cdio_default_log_handler(cdio_log_level_
         fprintf (stderr, "**ERROR: %s\n", message);
         fflush (stderr);
       }
-      exit (EXIT_FAILURE);
       break;
     case CDIO_LOG_DEBUG:
       if (level >= cdio_loglevel_default) {
