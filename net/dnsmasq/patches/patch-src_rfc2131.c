$NetBSD: patch-src_rfc2131.c,v 1.3 2023/02/25 03:30:47 riastradh Exp $

Fix ctype(3) misuse.

--- src/rfc2131.c.orig	2023-02-02 20:24:24.000000000 +0000
+++ src/rfc2131.c
@@ -1678,7 +1678,7 @@ static int sanitise(unsigned char *opt, 
   for (i = option_len(opt); i > 0; i--)
     {
       char c = *p++;
-      if (isprint((int)c))
+      if (isprint((unsigned char)c))
 	*buf++ = c;
     }
   *buf = 0; /* add terminator */
