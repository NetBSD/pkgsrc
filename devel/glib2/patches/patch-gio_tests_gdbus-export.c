$NetBSD: patch-gio_tests_gdbus-export.c,v 1.1 2019/06/21 20:21:00 prlw1 Exp $

Revert GHashTable improvements
https://gitlab.gnome.org/GNOME/glib/merge_requests/208

to fix PR pkg/54310

--- gio/tests/gdbus-export.c.orig	2019-06-10 17:47:20.000000000 +0000
+++ gio/tests/gdbus-export.c
@@ -337,22 +337,6 @@ introspect_callback (GDBusProxy   *proxy
   g_main_loop_quit (loop);
 }
 
-static gint
-compare_strings (gconstpointer a,
-                 gconstpointer b)
-{
-  const gchar *sa = *(const gchar **) a;
-  const gchar *sb = *(const gchar **) b;
-
-  /* Array terminator must sort last */
-  if (sa == NULL)
-    return 1;
-  if (sb == NULL)
-    return -1;
-
-  return strcmp (sa, sb);
-}
-
 static gchar **
 get_nodes_at (GDBusConnection  *c,
               const gchar      *object_path)
@@ -406,9 +390,6 @@ get_nodes_at (GDBusConnection  *c,
   g_free (xml_data);
   g_dbus_node_info_unref (node_info);
 
-  /* Nodes are semantically unordered; sort array so tests can rely on order */
-  g_ptr_array_sort (p, compare_strings);
-
   return (gchar **) g_ptr_array_free (p, FALSE);
 }
 
@@ -1259,9 +1240,9 @@ test_object_registration (void)
   nodes = get_nodes_at (c, "/foo/dyna");
   g_assert (nodes != NULL);
   g_assert_cmpint (g_strv_length (nodes), ==, 3);
-  g_assert_cmpstr (nodes[0], ==, "cat");
-  g_assert_cmpstr (nodes[1], ==, "cheezburger");
-  g_assert_cmpstr (nodes[2], ==, "lol");
+  g_assert_cmpstr (nodes[0], ==, "lol");
+  g_assert_cmpstr (nodes[1], ==, "cat");
+  g_assert_cmpstr (nodes[2], ==, "cheezburger");
   g_strfreev (nodes);
   g_assert_cmpint (count_interfaces (c, "/foo/dyna/lol"), ==, 4);
   g_assert_cmpint (count_interfaces (c, "/foo/dyna/cat"), ==, 4);
@@ -1272,10 +1253,10 @@ test_object_registration (void)
   nodes = get_nodes_at (c, "/foo/dyna");
   g_assert (nodes != NULL);
   g_assert_cmpint (g_strv_length (nodes), ==, 4);
-  g_assert_cmpstr (nodes[0], ==, "cat");
-  g_assert_cmpstr (nodes[1], ==, "cheezburger");
-  g_assert_cmpstr (nodes[2], ==, "dynamicallycreated");
-  g_assert_cmpstr (nodes[3], ==, "lol");
+  g_assert_cmpstr (nodes[0], ==, "lol");
+  g_assert_cmpstr (nodes[1], ==, "cat");
+  g_assert_cmpstr (nodes[2], ==, "cheezburger");
+  g_assert_cmpstr (nodes[3], ==, "dynamicallycreated");
   g_strfreev (nodes);
   g_assert_cmpint (count_interfaces (c, "/foo/dyna/dynamicallycreated"), ==, 4);
 
