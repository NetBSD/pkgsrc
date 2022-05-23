$NetBSD: patch-src_xa_xa__main.c,v 1.1 2022/05/23 19:10:03 plunky Exp $

1. don't hardwire location of examples.gz
2. don't use OSname in config dir name

--- src/xa/xa_main.c.orig	2021-07-18 06:38:57.000000000 +0000
+++ src/xa/xa_main.c
@@ -280,16 +280,10 @@ static int     lngNr;
 
 #else
   // POSTINSTALL:  extract <os_bas_dir>examples.gz -> local /cfg/
-  sprintf(txbuf2, "cd %s && tar -xzf /usr/share/gcad3d/examples.gz",
-          dirLocal);  //, OS_get_bas_dir());
+  sprintf(txbuf2, "cd %s && tar -xzf %sexamples.gz", dirLocal, os_bas_dir);
     printf("%s\n",txbuf2);
   system(txbuf2);
 
-  // rename dir. /cfg/ /cfg_Linux/ or /cfg_MS/
-  sprintf(txbuf1, "%scfg/", os_loc_dir);
-  sprintf(txbuf2, "%scfg_%s/", os_loc_dir, OS_get_os__());
-  OS_file_rename (txbuf1, txbuf2);
-
 /*
   // copy desktop-link -> ~/gCAD3D/gCAD3D.desktop
   sprintf(txbuf2, "cp -f /usr/share/gcad3d/gcad3d.desktop %s.",
@@ -795,7 +789,7 @@ kopieren geht nicht mehr - 
   strcpy(s1, os_loc_dir);
 //   strcat(s1, "cfg");
 //   UTX_add_fnam_del (s1);   // add closing "/"
-  sprintf(s1, "%scfg_%s%c", os_loc_dir, OS_get_os__(),fnam_del);
+  sprintf(s1, "%scfg%c", os_loc_dir, fnam_del);
 
   UtxTab_add (&AP_TxTab1, s1);
   UtxTab_query (&os_cfg_dir, &AP_TxTab1);
