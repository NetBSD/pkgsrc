$NetBSD: patch-gdk-pixbuf_io-icns.c,v 1.3.2.2 2017/06/02 19:54:50 bsiegert Exp $

from hint in https://bugzilla.gnome.org/show_bug.cgi?id=779016
for CVE-2017-6313

--- gdk-pixbuf/io-icns.c.orig	2016-10-22 03:38:29.000000000 +0000
+++ gdk-pixbuf/io-icns.c
@@ -95,7 +95,7 @@ load_resources (unsigned size, IN gpoint
       blocklen = GUINT32_FROM_BE (header->size);
 
       /* Check that blocklen isn't garbage */
-      if (blocklen > icnslen - (current - bytes))
+      if ((blocklen > icnslen - (current - bytes)) || (blocklen < sizeof (IcnsBlockHeader)))
         return FALSE;
 
       switch (size)
