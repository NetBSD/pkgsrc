$NetBSD: patch-lib_libpam_openpam__constants.c,v 1.1 2014/06/10 13:17:42 joerg Exp $

--- lib/libpam/openpam_constants.c.orig	2014-06-10 13:01:39.996428375 +0000
+++ lib/libpam/openpam_constants.c
@@ -127,10 +127,8 @@ const char *pam_sm_func_name[PAM_NUM_PRI
 };
 
 const char *openpam_policy_path[] = {
-	"/etc/pam.d/",
-	"/etc/pam.conf",
-	"/usr/local/etc/pam.d/",
-	"/usr/local/etc/pam.conf",
+	SYSCONFDIR "/pam.d/",
+	SYSCONFDIR "/pam.conf",
 	NULL
 };
 
