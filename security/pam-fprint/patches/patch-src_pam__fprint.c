$NetBSD: patch-src_pam__fprint.c,v 1.1 2012/11/23 12:30:01 joerg Exp $

--- src/pam_fprint.c.orig	2012-11-22 21:40:14.000000000 +0000
+++ src/pam_fprint.c
@@ -21,12 +21,14 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <pwd.h>
+#include <stdlib.h>
 #include <string.h>
 
 #include <fprint.h>
 
 #define PAM_SM_AUTH
 #include <security/pam_modules.h>
+#include <security/pam_appl.h>
 
 static int send_info_msg(pam_handle_t *pamh, char *msg)
 {
@@ -41,10 +43,10 @@ static int send_info_msg(pam_handle_t *p
 
     r = pam_get_item(pamh, PAM_CONV, (const void **) &pc);
 	if (r != PAM_SUCCESS)
-		return;
+		return r;
 
 	if (!pc || !pc->conv)
-		return;
+		return PAM_SERVICE_ERR;
 
 	return pc->conv(1, &msgp, &resp, pc->appdata_ptr);
 }
@@ -62,10 +64,10 @@ static int send_err_msg(pam_handle_t *pa
 
     r = pam_get_item(pamh, PAM_CONV, (const void **) &pc);
 	if (r != PAM_SUCCESS)
-		return;
+		return r;
 
 	if (!pc || !pc->conv)
-		return;
+		return PAM_SERVICE_ERR;
 
 	return pc->conv(1, &msgp, &resp, pc->appdata_ptr);
 }
@@ -97,7 +99,7 @@ static int find_dev_and_print(struct fp_
 	struct fp_dscv_print *print;
 	struct fp_dscv_dev *ddev;
 
-	while (print = prints[i++]) {
+	while ((print = prints[i++]) != NULL) {
 		ddev = fp_dscv_dev_for_dscv_print(ddevs, print);
 		if (ddev) {
 			*_ddev = ddev;
