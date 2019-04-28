$NetBSD: patch-src_osipparser2_osip__body.c,v 1.1.2.2 2019/04/28 16:14:29 bsiegert Exp $

Apply fix for CVE-2016-10326 (from Debian)

--- src/osipparser2/osip_body.c.orig	2013-12-18 18:36:46.000000000 +0000
+++ src/osipparser2/osip_body.c
@@ -417,6 +417,14 @@ osip_body_to_str (const osip_body_t * bo
   }
 
   if ((osip_list_size (body->headers) > 0) || (body->content_type != NULL)) {
+    if (length < tmp_body - ptr + 3) {
+      size_t len;
+
+      len = tmp_body - ptr;
+      length = length + 3 + body->length; /* add body->length, to avoid calling realloc often */
+      ptr = osip_realloc (ptr, length);
+      tmp_body = ptr + len;
+    }
     tmp_body = osip_strn_append (tmp_body, CRLF, 2);
   }
   if (length < tmp_body - ptr + body->length + 4) {
