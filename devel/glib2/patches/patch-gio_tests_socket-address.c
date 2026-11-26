$NetBSD: patch-gio_tests_socket-address.c,v 1.2 2026/11/26 06:35:27 adam Exp $

Avoid 'sun' define on illumos.

--- gio/tests/socket-address.c.orig	2026-11-25 14:25:19.000000000 +0000
+++ gio/tests/socket-address.c
@@ -11,7 +11,7 @@ static void
 test_socket_address_native_cornercases (void)
 {
   GSocketAddress *a;
-  struct sockaddr_un sun;
+  struct sockaddr_un sockun;
   struct sockaddr_un too_big[2];
   guint8 random_byte;
   GError *error = NULL;
@@ -20,25 +20,25 @@ test_socket_address_native_cornercases (
   g_assert_null (g_socket_address_new_from_native (NULL, 0));
 
   /* not null-terminated unix path */
-  memset (&sun, 'a', sizeof (struct sockaddr_un));
-  sun.sun_family = AF_UNIX;
-  a = g_socket_address_new_from_native (&sun, sizeof (sun));
+  memset (&sockun, 'a', sizeof (struct sockaddr_un));
+  sockun.sun_family = AF_UNIX;
+  a = g_socket_address_new_from_native (&sockun, sizeof (sockun));
   g_assert_nonnull (a);
   g_assert_true (G_IS_UNIX_SOCKET_ADDRESS (a));
   /* ensure this gets null-terminated by the constructor */
-  g_assert_cmpuint (g_unix_socket_address_get_path_len (G_UNIX_SOCKET_ADDRESS (a)), ==, sizeof (sun.sun_path));
+  g_assert_cmpuint (g_unix_socket_address_get_path_len (G_UNIX_SOCKET_ADDRESS (a)), ==, sizeof (sockun.sun_path));
   g_object_unref (a);
 
   /* unix path with embedded NULL */
-  sun.sun_path[4] = 0;
-  a = g_socket_address_new_from_native (&sun, sizeof (sun));
+  sockun.sun_path[4] = 0;
+  a = g_socket_address_new_from_native (&sockun, sizeof (sockun));
   g_assert_nonnull (a);
   g_assert_true (G_IS_UNIX_SOCKET_ADDRESS (a));
-  g_assert_cmpuint (g_unix_socket_address_get_path_len (G_UNIX_SOCKET_ADDRESS (a)), ==, sizeof (sun.sun_path));
+  g_assert_cmpuint (g_unix_socket_address_get_path_len (G_UNIX_SOCKET_ADDRESS (a)), ==, sizeof (sockun.sun_path));
   g_object_unref (a);
 
   /* specific test for an error check in g_socket_address_new_from_native() */
-  g_assert_null (g_socket_address_new_from_native (&sun, G_STRUCT_OFFSET (struct sockaddr_un, sun_path) - 1));
+  g_assert_null (g_socket_address_new_from_native (&sockun, G_STRUCT_OFFSET (struct sockaddr_un, sun_path) - 1));
 
   /* not null-terminated unix path */
   memset (&too_big, 'b', sizeof (too_big));
@@ -46,7 +46,7 @@ test_socket_address_native_cornercases (
   a = g_socket_address_new_from_native (too_big, sizeof (too_big));
   g_assert_nonnull (a);
   g_assert_true (G_IS_UNIX_SOCKET_ADDRESS (a));
-  g_assert_cmpuint (g_unix_socket_address_get_path_len (G_UNIX_SOCKET_ADDRESS (a)), ==, sizeof (sun.sun_path));
+  g_assert_cmpuint (g_unix_socket_address_get_path_len (G_UNIX_SOCKET_ADDRESS (a)), ==, sizeof (sockun.sun_path));
 
   /* check reading the path back out doesn't overflow */
   random_byte = g_test_rand_int_range ('c', 'z' + 1);
