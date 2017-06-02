$NetBSD: patch-gdk-pixbuf_io-tiff.c,v 1.1.2.2 2017/06/02 19:54:50 bsiegert Exp $

from https://bugzilla.gnome.org/attachment.cgi?id=350204&action=diff
for CVE-2017-6314

--- gdk-pixbuf/io-tiff.c.orig	2017-03-26 11:12:32.000000000 +0000
+++ gdk-pixbuf/io-tiff.c
@@ -505,9 +505,12 @@ make_available_at_least (TiffContext *co
         need_alloc = context->used + needed;
         if (need_alloc > context->allocated) {
                 guint new_size = 1;
-                while (new_size < need_alloc)
+                while (new_size && (new_size < need_alloc))
                         new_size *= 2;
 
+		if(!(new_size))
+			return FALSE;
+
                 new_buffer = g_try_realloc (context->buffer, new_size);
                 if (new_buffer) {
                         context->buffer = new_buffer;
