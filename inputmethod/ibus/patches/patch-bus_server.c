$NetBSD: patch-bus_server.c,v 1.1 2019/09/14 04:26:39 tsutsui Exp $

- pull upstream fixes
 - g_dbus_server_new_sync() is failed with address unix:tmpdir=/tmp/ibus
   https://github.com/ibus/ibus/issues/2116
 - bus: Implement GDBusAuthObserver callback
   https://github.com/ibus/ibus/commit/3d442dbf936d197aa11ca0a71663c2bc61696151

--- bus/server.c.orig	2019-08-23 11:08:34.000000000 +0000
+++ bus/server.c
@@ -2,7 +2,8 @@
 /* vim:set et sts=4: */
 /* bus - The Input Bus
  * Copyright (C) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
- * Copyright (C) 2008-2010 Red Hat, Inc.
+ * Copyright (C) 2011-2019 Takao Fujiwara <takao.fujiwara1@gmail.com>
+ * Copyright (C) 2008-2019 Red Hat, Inc.
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Lesser General Public
@@ -21,6 +22,8 @@
  */
 #include "server.h"
 
+#include <errno.h>
+#include <glib/gstdio.h>
 #include <gio/gio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -70,16 +73,63 @@ _restart_server (void)
 }
 
 /**
+ * bus_allow_mechanism_cb:
+ * @observer: A #GDBusAuthObserver.
+ * @mechanism: The name of the mechanism.
+ * @user_data: always %NULL.
+ *
+ * Check if @mechanism can be used to authenticate the other peer.
+ * Returns: %TRUE if the peer's mechanism is allowed.
+ */
+static gboolean
+bus_allow_mechanism_cb (GDBusAuthObserver     *observer,
+                        const gchar           *mechanism,
+                        G_GNUC_UNUSED gpointer user_data)
+{
+    if (g_strcmp0 (mechanism, "EXTERNAL") == 0)
+        return TRUE;
+    return FALSE;
+}
+
+/**
+ * bus_authorize_authenticated_peer_cb:
+ * @observer: A #GDBusAuthObserver.
+ * @stream: A #GIOStream.
+ * @credentials: A #GCredentials.
+ * @user_data: always %NULL.
+ *
+ * Check if a peer who has already authenticated should be authorized.
+ * Returns: %TRUE if the peer's credential is authorized.
+ */
+static gboolean
+bus_authorize_authenticated_peer_cb (GDBusAuthObserver     *observer,
+                                     GIOStream             *stream,
+                                     GCredentials          *credentials,
+                                     G_GNUC_UNUSED gpointer user_data)
+{
+    gboolean authorized = FALSE;
+    if (credentials) {
+        GCredentials *own_credentials = g_credentials_new ();
+        if (g_credentials_is_same_user (credentials, own_credentials, NULL))
+            authorized = TRUE;
+        g_object_unref (own_credentials);
+    }
+    return authorized;
+}
+
+/**
  * bus_new_connection_cb:
- * @user_data: always NULL.
- * @returns: TRUE when the function can handle the connection.
+ * @observer: A #GDBusAuthObserver.
+ * @dbus_connection: A #GDBusconnection.
+ * @user_data: always %NULL.
  *
  * Handle incoming connections.
+ * Returns: %TRUE when the function can handle the connection.
  */
 static gboolean
-bus_new_connection_cb (GDBusServer     *server,
-                       GDBusConnection *dbus_connection,
-                       gpointer         user_data)
+bus_new_connection_cb (GDBusServer           *server,
+                       GDBusConnection       *dbus_connection,
+                       G_GNUC_UNUSED gpointer user_data)
 {
     BusConnection *connection = bus_connection_new (dbus_connection);
     bus_dbus_impl_new_connection (dbus, connection);
@@ -94,9 +144,9 @@ bus_new_connection_cb (GDBusServer     *
 }
 
 static void
-_server_connect_start_portal_cb (GObject      *source_object,
-                                 GAsyncResult *res,
-                                 gpointer      user_data)
+_server_connect_start_portal_cb (GObject               *source_object,
+                                 GAsyncResult          *res,
+                                 G_GNUC_UNUSED gpointer user_data)
 {
     GVariant *result;
     GError *error = NULL;
@@ -113,9 +163,9 @@ _server_connect_start_portal_cb (GObject
 }
 
 static void
-bus_acquired_handler (GDBusConnection *connection,
-                      const gchar     *name,
-                      gpointer         user_data)
+bus_acquired_handler (GDBusConnection       *connection,
+                      const gchar           *name,
+                      G_GNUC_UNUSED gpointer user_data)
 {
     g_dbus_connection_call (connection,
                             IBUS_SERVICE_PORTAL,
@@ -132,37 +182,121 @@ bus_acquired_handler (GDBusConnection *c
                             NULL);
 }
 
+static gchar *
+_bus_extract_address (void)
+{
+    gchar *socket_address = g_strdup (g_address);
+    gchar *p;
+
+#define IF_REPLACE_VARIABLE_WITH_FUNC(variable, func, format)           \
+    if ((p = g_strstr_len (socket_address, -1, (variable)))) {          \
+        gchar *sub1 = g_strndup (socket_address, p - socket_address);   \
+        gchar *sub2 = g_strdup (p + strlen (variable));                 \
+        gchar *tmp = g_strdup_printf ("%s" format "%s",                 \
+                                      sub1, (func) (), sub2);           \
+        g_free (sub1);                                                  \
+        g_free (sub2);                                                  \
+        g_free (socket_address);                                        \
+        socket_address = tmp;                                           \
+    }
+
+    IF_REPLACE_VARIABLE_WITH_FUNC ("$XDG_RUNTIME_DIR",
+                                   g_get_user_runtime_dir,
+                                   "%s")
+    else
+    IF_REPLACE_VARIABLE_WITH_FUNC ("$XDG_CACHE_HOME",
+                                   g_get_user_cache_dir,
+                                   "%s")
+    else
+    IF_REPLACE_VARIABLE_WITH_FUNC ("$UID", getuid, "%d")
+
+#undef IF_REPLACE_VARIABLE_WITH_FUNC
+
+    return socket_address;
+}
+
 void
 bus_server_init (void)
 {
+#define IBUS_UNIX_TMPDIR        "unix:tmpdir="
+#define IBUS_UNIX_PATH          "unix:path="
+#define IBUS_UNIX_ABSTRACT      "unix:abstract="
+#define IBUS_UNIX_DIR           "unix:dir="
+
+    gchar *socket_address;
+    GDBusServerFlags flags = G_DBUS_SERVER_FLAGS_NONE;
+    gchar *guid;
+    GDBusAuthObserver *observer;
     GError *error = NULL;
+    gchar *unix_dir = NULL;
 
     dbus = bus_dbus_impl_get_default ();
     ibus = bus_ibus_impl_get_default ();
     bus_dbus_impl_register_object (dbus, (IBusService *)ibus);
 
     /* init server */
-    GDBusServerFlags flags = G_DBUS_SERVER_FLAGS_AUTHENTICATION_ALLOW_ANONYMOUS;
-    gchar *guid = g_dbus_generate_guid ();
-    if (!g_str_has_prefix (g_address, "unix:tmpdir=") &&
-        !g_str_has_prefix (g_address, "unix:path=")) {
-        g_error ("Your socket address does not have the format unix:tmpdir=$DIR "
-                 "or unix:path=$FILE; %s", g_address);
+    socket_address = _bus_extract_address ();
+
+#define IF_GET_UNIX_DIR(prefix)                                         \
+    if (g_str_has_prefix (socket_address, (prefix))) {                  \
+        unix_dir = g_strdup (socket_address + strlen (prefix));         \
     }
+
+    IF_GET_UNIX_DIR (IBUS_UNIX_TMPDIR)
+    else
+    IF_GET_UNIX_DIR (IBUS_UNIX_PATH)
+    else
+    IF_GET_UNIX_DIR (IBUS_UNIX_ABSTRACT)
+    else
+    IF_GET_UNIX_DIR (IBUS_UNIX_DIR)
+    else {
+        g_error ("Your socket address \"%s\" does not correspond with "
+                 "one of the following formats; "
+                 IBUS_UNIX_TMPDIR "DIR, " IBUS_UNIX_PATH "FILE, "
+                 IBUS_UNIX_ABSTRACT "FILE, " IBUS_UNIX_DIR "DIR.",
+                 socket_address);
+    }
+    if (!g_file_test (unix_dir, G_FILE_TEST_EXISTS | G_FILE_TEST_IS_DIR)) {
+        /* Require mkdir for BSD system. */
+        if (g_mkdir_with_parents (unix_dir, 0) != 0) {
+            g_error ("mkdir is failed in: %s: %s",
+                     unix_dir, g_strerror (errno));
+        }
+        /* The mode 0700 can eliminate malicious users change the mode.
+         * `chmod` runs for the last directory only not to change the modes
+         * of the parent directories. E.g. "/tmp/ibus".
+         */
+        if (g_chmod (unix_dir, 0700) != 0) {
+            g_error ("chmod(700) is failed in: %s: %s",
+                     unix_dir, g_strerror (errno));
+        }
+    }
+    g_free (unix_dir);
+    guid = g_dbus_generate_guid ();
+    observer = g_dbus_auth_observer_new ();
     server =  g_dbus_server_new_sync (
-                    g_address, /* the place where the socket file lives, e.g. /tmp, abstract namespace, etc. */
+                    /* the place where the socket file lives, e.g. /tmp,
+                     * abstract namespace, etc. */
+                    socket_address,
                     flags, guid,
-                    NULL /* observer */,
+                    observer,
                     NULL /* cancellable */,
                     &error);
     if (server == NULL) {
         g_error ("g_dbus_server_new_sync() is failed with address %s "
                  "and guid %s: %s",
-                 g_address, guid, error->message);
+                 socket_address, guid, error->message);
     }
+    g_free (socket_address);
     g_free (guid);
 
-    g_signal_connect (server, "new-connection", G_CALLBACK (bus_new_connection_cb), NULL);
+    g_signal_connect (observer, "allow-mechanism",
+                      G_CALLBACK (bus_allow_mechanism_cb), NULL);
+    g_signal_connect (observer, "authorize-authenticated-peer",
+                      G_CALLBACK (bus_authorize_authenticated_peer_cb), NULL);
+    g_object_unref (observer);
+    g_signal_connect (server, "new-connection",
+                      G_CALLBACK (bus_new_connection_cb), NULL);
 
     g_dbus_server_start (server);
 
@@ -178,6 +312,12 @@ bus_server_init (void)
                     G_BUS_NAME_OWNER_FLAGS_NONE,
                     bus_acquired_handler,
                     NULL, NULL, NULL, NULL);
+
+#undef IF_GET_UNIX_DIR
+#undef IBUS_UNIX_TMPDIR
+#undef IBUS_UNIX_PATH
+#undef IBUS_UNIX_ABSTRACT
+#undef IBUS_UNIX_DIR
 }
 
 const gchar *
