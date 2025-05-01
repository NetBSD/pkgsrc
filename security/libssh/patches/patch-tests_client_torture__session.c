$NetBSD: patch-tests_client_torture__session.c,v 1.1 2025/05/01 18:19:22 tnn Exp $

OpenSSH 10 support: https://gitlab.com/libssh/libssh-mirror/-/commit/d758990d392fbbca623afd22186164cb4ccf1743.patch
 
--- tests/client/torture_session.c.orig	2024-08-09 16:37:15.000000000 +0000
+++ tests/client/torture_session.c
@@ -574,6 +574,18 @@ static void torture_pubkey_hash(void **s
     }
 }
 
+static void torture_openssh_banner_version(void **state)
+{
+    struct torture_state *s = *state;
+    ssh_session session = s->ssh.session;
+
+    int openssh_version = ssh_get_openssh_version(session);
+    int cmake_openssh_version = SSH_VERSION_INT(OPENSSH_VERSION_MAJOR, OPENSSH_VERSION_MINOR, 0);
+
+    assert_int_equal(openssh_version, cmake_openssh_version);
+}
+
+
 int torture_run_tests(void) {
     int rc;
     struct CMUnitTest tests[] = {
@@ -619,6 +631,9 @@ int torture_run_tests(void) {
         cmocka_unit_test_setup_teardown(torture_pubkey_hash,
                                         session_setup,
                                         session_teardown),
+        cmocka_unit_test_setup_teardown(torture_openssh_banner_version,
+                                        session_setup,
+                                        session_teardown),
     };
 
     ssh_init();
