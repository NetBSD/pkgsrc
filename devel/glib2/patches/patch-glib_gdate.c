$NetBSD: patch-glib_gdate.c,v 1.1 2016/02/23 11:27:55 wiz Exp $

https://git.gnome.org/browse/glib/commit/?id=0817af40e8c74c721c30f6ef482b1f53d12044c7
Merged upstream. Remove this in next release.

--- glib/gdate.c.orig	2014-12-19 21:49:48.000000000 +0000
+++ glib/gdate.c
@@ -2494,7 +2494,10 @@ g_date_strftime (gchar       *s, 
        * recognize whether strftime actually failed or just returned "".
        */
       tmpbuf[0] = '\1';
+      #pragma GCC diagnostic push
+      #pragma GCC diagnostic ignored "-Wformat-nonliteral"
       tmplen = strftime (tmpbuf, tmpbufsize, locale_format, &tm);
+      #pragma GCC diagnostic pop
 
       if (tmplen == 0 && tmpbuf[0] != '\0')
         {
