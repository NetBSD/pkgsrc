$NetBSD: patch-misc.c,v 1.1 2015/04/08 18:45:22 ryoon Exp $

--- misc.c.orig	2015-02-28 15:33:27.000000000 +0000
+++ misc.c
@@ -964,7 +964,7 @@ int validate_manual_hostkey(char *key)
                 if (q[3*i+2] != ':')
                     goto not_fingerprint; /* sorry */
             for (i = 0; i < 16*3 - 1; i++)
-                key[i] = tolower(q[i]);
+                key[i] = tolower((unsigned char)(q[i]));
             key[16*3 - 1] = '\0';
             return TRUE;
         }
