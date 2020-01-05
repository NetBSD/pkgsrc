$NetBSD: patch-src_wayland-server.c,v 1.2 2020/01/05 19:30:48 nia Exp $

NetBSD support

--- src/wayland-server.c.orig	2019-03-21 00:55:25.000000000 +0000
+++ src/wayland-server.c
@@ -43,6 +43,13 @@
 #include <sys/file.h>
 #include <sys/stat.h>
 
+#include "../config.h"
+
+#ifdef HAVE_SYS_UCRED_H
+#include <sys/types.h>
+#include <sys/ucred.h>
+#endif
+
 #include "wayland-util.h"
 #include "wayland-private.h"
 #include "wayland-server.h"
@@ -77,7 +84,17 @@ struct wl_client {
 	struct wl_list link;
 	struct wl_map objects;
 	struct wl_priv_signal destroy_signal;
+#ifdef HAVE_SYS_UCRED_H
+#ifdef __NetBSD__
+	struct uucred ucred;
+#else
+	/* FreeBSD */
+	struct xucred ucred;
+#endif
+#else
+	/* Linux */
 	struct ucred ucred;
+#endif
 	int error;
 	struct wl_priv_signal resource_created_signal;
 };
@@ -312,7 +329,11 @@ wl_resource_post_error(struct wl_resourc
 static void
 destroy_client_with_error(struct wl_client *client, const char *reason)
 {
+#ifdef __linux__
 	wl_log("%s (pid %u)\n", reason, client->ucred.pid);
+#else
+	wl_log("Destroying with error: %s\n", reason);
+#endif
 	wl_client_destroy(client);
 }
 
@@ -527,9 +548,11 @@ wl_client_create(struct wl_display *disp
 		goto err_client;
 
 	len = sizeof client->ucred;
+#ifdef SO_PEERCRED
 	if (getsockopt(fd, SOL_SOCKET, SO_PEERCRED,
 		       &client->ucred, &len) < 0)
 		goto err_source;
+#endif
 
 	client->connection = wl_connection_create(fd);
 	if (client->connection == NULL)
@@ -583,12 +606,23 @@ WL_EXPORT void
 wl_client_get_credentials(struct wl_client *client,
 			  pid_t *pid, uid_t *uid, gid_t *gid)
 {
+#ifdef HAVE_SYS_UCRED_H
+	/* BSD */
+	if (pid)
+		*pid = 0; /* FIXME: should be set*/
+	if (uid)
+		*uid = client->ucred.cr_uid;
+	if (gid)
+		*gid = client->ucred.cr_gid;
+#else
+	/* Linux */
 	if (pid)
 		*pid = client->ucred.pid;
 	if (uid)
 		*uid = client->ucred.uid;
 	if (gid)
 		*gid = client->ucred.gid;
+#endif
 }
 
 /** Get the file descriptor for the client
