$NetBSD: patch-gio_tests_credentials.c,v 1.1 2014/09/05 20:49:55 prlw1 Exp $

gcredentials: add NetBSD support
https://bugzilla.gnome.org/show_bug.cgi?id=728256

--- gio/tests/credentials.c.orig	2014-01-06 19:02:48.000000000 +0000
+++ gio/tests/credentials.c
@@ -100,6 +100,14 @@ test_basic (void)
           g_assert_cmpuint (native->cmcred_euid, ==, geteuid ());
           g_assert_cmpuint (native->cmcred_pid, ==, getpid ());
         }
+#elif G_CREDENTIALS_USE_NETBSD_UNPCBID
+        {
+          struct unpcbid *native = g_credentials_get_native (creds,
+              G_CREDENTIALS_TYPE_NETBSD_UNPCBID);
+
+          g_assert_cmpuint (native->unp_euid, ==, geteuid ());
+          g_assert_cmpuint (native->unp_pid, ==, getpid ());
+        }
 #elif G_CREDENTIALS_USE_OPENBSD_SOCKPEERCRED
         {
           struct sockpeercred *native = g_credentials_get_native (creds,
