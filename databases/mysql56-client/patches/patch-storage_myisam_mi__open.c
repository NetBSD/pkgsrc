$NetBSD: patch-storage_myisam_mi__open.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- storage/myisam/mi_open.c.orig	2013-04-28 14:00:37.000000000 +0000
+++ storage/myisam/mi_open.c
@@ -510,7 +510,7 @@ MI_INFO *mi_open(const char *name, int m
       info.s=share;
       if (_mi_read_pack_info(&info,
 			     (pbool)
-			     test(!(share->options &
+			     my_test(!(share->options &
 				    (HA_OPTION_PACK_RECORD |
 				     HA_OPTION_TEMP_COMPRESS_RECORD)))))
 	goto err;
