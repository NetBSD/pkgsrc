$NetBSD: patch-we__fl__unix.c,v 1.1 2025/06/02 12:54:30 vins Exp $

Fix format-security warning in printf() usage.

--- we_fl_unix.c.orig	2005-07-07 01:53:09.000000000 +0000
+++ we_fl_unix.c
@@ -1044,7 +1044,7 @@ int WpeHandleFileManager(ECNT * cn)
           }
           else if(!WpeIsXwin())
           {
-            printf(e_msg[ERR_HITCR]);
+            printf("%s", e_msg[ERR_HITCR]);
             fflush(stderr);
             fflush(stdout);
             fk_getch();
