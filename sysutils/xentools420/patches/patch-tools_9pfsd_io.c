$NetBSD: patch-tools_9pfsd_io.c,v 1.1 2025/08/22 09:00:13 bouyer Exp $

Don't use non-standard d_off, use telldir(3) instead

--- tools/9pfsd/io.c.orig	2025-08-21 17:42:32.397455897 +0200
+++ tools/9pfsd/io.c	2025-08-21 17:45:14.125083684 +0200
@@ -1321,7 +1321,7 @@
             fill_p9_stat(device, &p9s, &st, dirent->d_name);
             if ( p9s.size + sizeof(p9s.size) > len )
             {
-                seekdir(fidp->data, dirent->d_off);
+                seekdir(fidp->data, telldir(fidp->data));
                 break;
             }
             fill_buffer_at(&buf, "s", &p9s);
