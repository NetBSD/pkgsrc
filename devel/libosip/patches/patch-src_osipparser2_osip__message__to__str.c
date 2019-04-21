$NetBSD: patch-src_osipparser2_osip__message__to__str.c,v 1.1 2019/04/21 16:25:38 khorben Exp $

Apply fix for CVE-2016-10325 (from Debian)

--- src/osipparser2/osip_message_to_str.c.orig	2013-12-18 18:36:46.000000000 +0000
+++ src/osipparser2/osip_message_to_str.c
@@ -378,6 +378,13 @@ _osip_message_to_str (osip_message_t * s
     /* A start-line isn't required for message/sipfrag parts. */
   }
   else {
+    size_t message_len = strlen(tmp);
+    if (_osip_message_realloc (&message, dest, message_len + 3, &malloc_size) < 0) {
+      osip_free (tmp);
+      *dest = NULL;
+      return OSIP_NOMEM;
+    }
+
     message = osip_str_append (message, tmp);
     osip_free (tmp);
     message = osip_strn_append (message, CRLF, 2);
