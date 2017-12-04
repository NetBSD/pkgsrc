$NetBSD: patch-bus_at-spi-bus-launcher.c,v 1.1 2017/12/04 16:36:24 maya Exp $

Fix inverted logic. Don't write to a buffer more than it can hold.
https://bugzilla.gnome.org/show_bug.cgi?id=791124

--- bus/at-spi-bus-launcher.c.orig	2017-06-20 17:27:11.000000000 +0000
+++ bus/at-spi-bus-launcher.c
@@ -244,7 +244,7 @@ unix_read_all_fd_to_string (int      fd,
 {
   ssize_t bytes_read;
 
-  while (max_bytes > 1 && (bytes_read = read (fd, buf, MAX (4096, max_bytes - 1))))
+  while (max_bytes > 1 && (bytes_read = read (fd, buf, MIN (4096, max_bytes - 1))))
     {
       if (bytes_read < 0)
         return FALSE;
