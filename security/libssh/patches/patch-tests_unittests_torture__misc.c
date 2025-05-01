$NetBSD: patch-tests_unittests_torture__misc.c,v 1.1 2025/05/01 18:19:22 tnn Exp $

OpenSSH 10 support: https://gitlab.com/libssh/libssh-mirror/-/commit/d758990d392fbbca623afd22186164cb4ccf1743.patch

--- tests/unittests/torture_misc.c.orig	2024-08-29 13:01:56.000000000 +0000
+++ tests/unittests/torture_misc.c
@@ -339,6 +339,7 @@ static void torture_ssh_analyze_banner(v
     assert_server_banner_accepted("SSH-2.0-OpenSSH");
     assert_int_equal(0, session->openssh);
 
+
     /* OpenSSH banners: big enough to extract major and minor versions */
     assert_client_banner_accepted("SSH-2.0-OpenSSH_5.9p1");
     assert_int_equal(SSH_VERSION_INT(5, 9, 0), session->openssh);
@@ -378,6 +379,10 @@ static void torture_ssh_analyze_banner(v
     assert_server_banner_accepted("SSH-2.0-OpenSSH-keyscan");
     assert_int_equal(0, session->openssh);
 
+    /* OpenSSH banners: Double digit in major version */
+    assert_server_banner_accepted("SSH-2.0-OpenSSH_10.0p1");
+    assert_int_equal(SSH_VERSION_INT(10, 0, 0), session->openssh);
+
     ssh_free(session);
 }
 
