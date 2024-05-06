$NetBSD: patch-IMG__gif.c,v 1.1 2024/05/06 18:05:32 nia Exp $

Fix CVE-2017-14450. Taken from Ubuntu Linux.

--- IMG_gif.c.orig	2016-01-03 05:52:28.000000000 +0000
+++ IMG_gif.c
@@ -500,8 +500,10 @@ LWZReadByte(SDL_RWops *src, int flag, in
             return -3;
         }
         *sp++ = table[1][code];
-        if (code == table[0][code])
-        RWSetMsg("circular table entry BIG ERROR");
+        if (code == table[0][code]) {
+            RWSetMsg("circular table entry BIG ERROR");
+            return -3;
+        }
         code = table[0][code];
     }
 
