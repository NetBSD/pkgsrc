$NetBSD: patch-source4_torture_local_nss__tests.c,v 1.1 2018/12/22 01:13:52 adam Exp $

Fix for systems without getpwent_r() and getgrent_r().

--- source4/torture/local/nss_tests.c.orig	2018-12-21 18:31:03.000000000 +0000
+++ source4/torture/local/nss_tests.c
@@ -346,6 +346,7 @@ static bool test_enum_r_passwd(struct to
 	torture_comment(tctx, "Testing setpwent\n");
 	setpwent();
 
+#ifdef HAVE_GETPWENT_R
 	while (1) {
 		torture_comment(tctx, "Testing getpwent_r\n");
 
@@ -368,6 +369,7 @@ static bool test_enum_r_passwd(struct to
 			num_pwd++;
 		}
 	}
+#endif /* HAVE_GETPWENT_R */
 
 	torture_comment(tctx, "Testing endpwent\n");
 	endpwent();
@@ -544,6 +546,7 @@ static bool test_enum_r_group(struct tor
 	torture_comment(tctx, "Testing setgrent\n");
 	setgrent();
 
+#ifdef HAVE_GETGRENT_R
 	while (1) {
 		torture_comment(tctx, "Testing getgrent_r\n");
 
@@ -566,6 +569,7 @@ static bool test_enum_r_group(struct tor
 			num_grp++;
 		}
 	}
+#endif /* HAVE_GETGRENT_R */
 
 	torture_comment(tctx, "Testing endgrent\n");
 	endgrent();
