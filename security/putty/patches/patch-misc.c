$NetBSD: patch-misc.c,v 1.2 2019/04/01 12:10:43 ryoon Exp $

--- misc.c.orig	2019-03-16 12:26:34.000000000 +0000
+++ misc.c
@@ -158,7 +158,7 @@ bool validate_manual_hostkey(char *key)
                 if (q[3*i+2] != ':')
                     goto not_fingerprint; /* sorry */
             for (i = 0; i < 16*3 - 1; i++)
-                key[i] = tolower(q[i]);
+                key[i] = tolower((unsigned char)(q[i]));
             key[16*3 - 1] = '\0';
             return true;
         }
