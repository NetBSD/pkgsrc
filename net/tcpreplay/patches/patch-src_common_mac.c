$NetBSD: patch-src_common_mac.c,v 1.1 2017/12/04 09:32:01 he Exp $

Ensure args to toxxxx() are within allowed value range.

--- ./src/common/mac.c.orig	2017-05-09 14:17:52.000000000 +0000
+++ ./src/common/mac.c
@@ -42,7 +42,7 @@ mac2hex(const char *mac, u_char *dst, in
     if (len < 6)
         return;
 
-    while (isspace(*mac))
+    while (isspace((unsigned char)*mac))
         mac++;
 
     /* expect 6 hex octets separated by ':' or space/NUL if last octet */
@@ -50,7 +50,7 @@ mac2hex(const char *mac, u_char *dst, in
         l = strtol(mac, &pp, 16);
         if (pp == mac || l > 0xFF || l < 0)
             return;
-        if (!(*pp == ':' || (i == 5 && (isspace(*pp) || *pp == '\0'))))
+        if (!(*pp == ':' || (i == 5 && (isspace((unsigned char)*pp) || *pp == '\0'))))
             return;
         dst[i] = (u_char) l;
         mac = pp + 1;
