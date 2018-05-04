$NetBSD: patch-pam__mkhomedir.c,v 1.1 2018/05/04 14:52:26 he Exp $

Fix typo causing buffer overflow(!)

--- pam_mkhomedir.c.orig	2018-05-04 14:29:55.000000000 +0000
+++ pam_mkhomedir.c
@@ -208,7 +208,7 @@ pam_mkhd_copy(pam_handle_t *pamh, const 
 			return PAM_PERM_DENIED;
 		}
 
-		while ((len = read(ffd, newto, 65546)) > 0)
+		while ((len = read(ffd, newto, 65536)) > 0)
 		{
 			if (write(tfd, newto, len) == -1)
 			{
