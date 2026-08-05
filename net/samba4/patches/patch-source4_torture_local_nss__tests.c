$NetBSD: patch-source4_torture_local_nss__tests.c,v 1.3.2.2 2026/08/05 14:54:59 maya Exp $

Fix illumos getpwent_r/getgrent_r arguments.

--- source4/torture/local/nss_tests.c.orig	2026-07-29 16:57:02.512027378 +0000
+++ source4/torture/local/nss_tests.c
@@ -351,7 +351,8 @@ static bool test_enum_r_passwd(struct to
 		torture_comment(tctx, "Testing getpwent_r\n");
 
 #ifdef SOLARIS_GETPWENT_R
-		ret = getpwent_r(&pwd, buffer, sizeof(buffer));
+		pwdp = getpwent_r(&pwd, buffer, sizeof(buffer));
+		ret = (pwdp != NULL) ? 0 : errno;
 #else /* SOLARIS_GETPWENT_R */
 		ret = getpwent_r(&pwd, buffer, sizeof(buffer), &pwdp);
 #endif /* SOLARIS_GETPWENT_R */
@@ -551,7 +552,8 @@ static bool test_enum_r_group(struct tor
 		torture_comment(tctx, "Testing getgrent_r\n");
 
 #ifdef SOLARIS_GETGRENT_R
-		ret = getgrent_r(&grp, buffer, sizeof(buffer));
+		grpp = getgrent_r(&grp, buffer, sizeof(buffer));
+		ret = (grpp != NULL) ? 0 : errno;
 #else /* SOLARIS_GETGRENT_R */
 		ret = getgrent_r(&grp, buffer, sizeof(buffer), &grpp);
 #endif /* SOLARIS_GETGRENT_R */
