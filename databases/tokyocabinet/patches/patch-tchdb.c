$NetBSD: patch-tchdb.c,v 1.1 2013/10/25 20:27:18 jperkin Exp $

Fix return types.

--- tchdb.c.orig	2012-08-18 02:08:38.000000000 +0000
+++ tchdb.c
@@ -697,7 +697,7 @@ void *tchdbget(TCHDB *hdb, const void *k
   }
   if(!HDBLOCKRECORD(hdb, bidx, false)){
     HDBUNLOCKMETHOD(hdb);
-    return false;
+    return NULL;
   }
   char *rv = tchdbgetimpl(hdb, kbuf, ksiz, bidx, hash, sp);
   HDBUNLOCKRECORD(hdb, bidx);
