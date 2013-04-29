$NetBSD: patch-vio_vio.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- vio/vio.c.orig	2013-04-28 14:09:38.000000000 +0000
+++ vio/vio.c
@@ -202,7 +202,7 @@ my_bool vio_reset(Vio* vio, enum enum_vi
   if (old_vio.write_timeout >= 0)
     ret|= vio_timeout(vio, 1, old_vio.write_timeout);
 
-  DBUG_RETURN(test(ret));
+  DBUG_RETURN(my_test(ret));
 }
 
 
