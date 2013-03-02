$NetBSD: patch-lib_ext_wocky_tests_wocky-connector-test.c,v 1.1 2013/03/02 18:19:10 joerg Exp $

--- lib/ext/wocky/tests/wocky-connector-test.c.orig	2013-03-01 14:38:21.000000000 +0000
+++ lib/ext/wocky/tests/wocky-connector-test.c
@@ -3428,7 +3428,7 @@ run_test (gpointer data)
 
           g_object_get (wcon, "identity", &identity, "features", &feat, NULL);
           g_assert (identity != NULL);
-          g_assert (*identity |= '\0');
+          g_assert (*identity != '\0');
           g_assert (feat != NULL);
           g_assert (G_OBJECT_TYPE (feat) == WOCKY_TYPE_STANZA);
           g_free (identity);
@@ -3442,7 +3442,7 @@ run_test (gpointer data)
 
           g_object_get (wcon, "resource", &identity, NULL);
           g_assert (identity != NULL);
-          g_assert (*identity |= '\0');
+          g_assert (*identity != '\0');
           g_free (identity);
 
           g_object_get (wcon, "legacy", &jabber, "old-ssl", &oldssl, NULL);
