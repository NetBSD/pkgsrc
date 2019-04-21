$NetBSD: patch-src_osipparser2_osip__message__parse.c,v 1.1 2019/04/21 16:25:38 khorben Exp $

Apply fix for CVE-2017-7853 (from Debian)

--- src/osipparser2/osip_message_parse.c.orig	2013-12-18 18:36:46.000000000 +0000
+++ src/osipparser2/osip_message_parse.c
@@ -812,6 +812,12 @@ msg_osip_body_parse (osip_message_t * si
     if ('\n' == start_of_body[0] || '\r' == start_of_body[0])
       start_of_body++;
 
+    /* if message body is empty or contains a single CR/LF */
+    if (end_of_body <= start_of_body) {
+      osip_free (sep_boundary);
+      return OSIP_SYNTAXERROR;
+    }
+
     body_len = end_of_body - start_of_body;
 
     /* Skip CR before end boundary. */
