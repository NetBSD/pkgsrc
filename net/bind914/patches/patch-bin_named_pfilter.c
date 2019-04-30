$NetBSD: patch-bin_named_pfilter.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* Add support for blacklistd.

--- bin/named/pfilter.c.orig	2019-04-29 08:47:44.504984633 +0000
+++ bin/named/pfilter.c
@@ -0,0 +1,51 @@
+#include <config.h>
+
+#include <isc/platform.h>
+#include <isc/util.h>
+#include <named/types.h>
+#include <ns/client.h>
+
+#ifdef HAVE_BLACKLIST
+
+#include <blacklist.h>
+
+#include "pfilter.h"
+
+static struct blacklist *blstate;
+
+void
+pfilter_open(void)
+{
+	if (blstate == NULL)
+		blstate = blacklist_open();
+}
+
+#define TCP_CLIENT(c)  (((c)->attributes & NS_CLIENTATTR_TCP) != 0)
+
+void
+pfilter_notify(isc_result_t res, ns_client_t *client, const char *msg)
+{
+	isc_socket_t *socket;
+
+	pfilter_open();
+
+	if (TCP_CLIENT(client))
+		socket = client->tcpsocket;
+	else {
+		socket = client->udpsocket;
+		if (!client->peeraddr_valid)
+			return;
+	}
+
+	if (socket == NULL)
+		return;
+
+	if (blstate == NULL)
+		return;
+
+	blacklist_sa_r(blstate, 
+	    res != ISC_R_SUCCESS, isc_socket_getfd(socket),
+	    &client->peeraddr.type.sa, client->peeraddr.length, msg);
+}
+
+#endif /* HAVE_BLACKLIST */
