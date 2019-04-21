$NetBSD: patch-src_osipparser2_osip__port.c,v 1.1 2019/04/21 16:25:38 khorben Exp $

Apply fix for CVE-2016-10324 (from Debian)

--- src/osipparser2/osip_port.c.orig	2013-12-18 18:36:46.000000000 +0000
+++ src/osipparser2/osip_port.c
@@ -1462,8 +1462,10 @@ osip_clrncpy (char *dst, const char *src
   char *p;
   size_t spaceless_length;
 
-  if (src == NULL)
+  if (src == NULL || len == 0) {
+    *dst = '\0';
     return NULL;
+  }
 
   /* find the start of relevant text */
   pbeg = src;
