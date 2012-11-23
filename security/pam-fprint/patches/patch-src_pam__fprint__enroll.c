$NetBSD: patch-src_pam__fprint__enroll.c,v 1.1 2012/11/23 12:30:01 joerg Exp $

--- src/pam_fprint_enroll.c.orig	2012-11-22 21:39:34.000000000 +0000
+++ src/pam_fprint_enroll.c
@@ -47,7 +47,7 @@ static struct fp_dscv_dev *discover_devi
 	struct fp_dscv_dev *ddev = NULL;
 	int i;
 
-	for (i = 0; ddev = discovered_devs[i]; i++) {
+	for (i = 0; (ddev = discovered_devs[i]) != NULL; i++) {
 		struct fp_driver *drv = fp_dscv_dev_get_driver(ddev);
 		printf("Found device claimed by %s driver\n",
 			fp_driver_get_full_name(drv));
