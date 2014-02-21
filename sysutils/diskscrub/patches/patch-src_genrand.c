$NetBSD: patch-src_genrand.c,v 1.2 2014/02/21 01:13:00 prlw1 Exp $

Fix missing return value.

--- src/genrand.c.orig	2013-12-15 13:03:04.000000000 +0000
+++ src/genrand.c
@@ -106,7 +106,7 @@ genrandraw(unsigned char *buf, int bufle
                 buf[n] = result;
             }
 #endif
-            return;
+            return 0;
         }
     }
 
