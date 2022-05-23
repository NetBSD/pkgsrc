$NetBSD: patch-src_xa_xa.c,v 1.1 2022/05/23 19:10:03 plunky Exp $

don't use OS name in config dir name

--- src/xa/xa.c.orig	2021-07-28 14:44:53.384469360 +0000
+++ src/xa/xa.c
@@ -3451,7 +3451,7 @@ remote control nur in VWR, nicht MAN, CA
 
 
   // MDLFN_syFn_f_name (txbuf);   // get filename of dir.lst (<cfg>/dir.lst)
-  sprintf(txbuf, "%scfg_%s%cdir.lst",OS_get_loc_dir(),OS_get_os__(),fnam_del);
+  sprintf(txbuf, "%scfg%cdir.lst",OS_get_loc_dir(),fnam_del);
 
   printf("AP_defaults_dir %s\n",txbuf);
 
