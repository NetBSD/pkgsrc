$NetBSD: patch-etc_cnid_dbd_cmd_dbd_scanvol.c,v 1.1 2021/04/02 09:54:26 hauke Exp $

While upstream "officially" only supports unicode volumes, other
encodings have always worked. So, starting to enforce unicode volumes
in the repair tool is a funny approach.

--- etc/cnid_dbd/cmd_dbd_scanvol.c.orig	2014-03-16 11:17:48.000000000 +0000
+++ etc/cnid_dbd/cmd_dbd_scanvol.c
@@ -1204,10 +1204,10 @@ int cmd_dbd_scanvol(DBD *dbd_ref, struct
     /* Make it accessible for all funcs */
     dbd = dbd_ref;
 
-    /* We only support unicode volumes ! */
+    /* Officially, we only support unicode volumes */
     if ( vi->v_volcharset != CH_UTF8) {
         dbd_log( LOGSTD, "Not a Unicode volume: %s, %u != %u", vi->v_volcodepage, vi->v_volcharset, CH_UTF8);
-        return -1;
+        /* return -1; */
     }
 
     /* Get volume stamp */
