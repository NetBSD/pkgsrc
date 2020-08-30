$NetBSD: patch-lib_ns_pfilter.c,v 1.2 2020/08/30 19:26:45 christos Exp $

* Take from NetBSD base.

--- lib/ns/pfilter.c.orig	2020-08-30 14:56:09.038428676 -0400
+++ lib/ns/pfilter.c	2020-08-30 15:07:25.182798415 -0400
@@ -0,0 +1,55 @@
+
+#include "config.h"
+
+#include <isc/platform.h>
+#include <isc/util.h>
+#include <ns/types.h>
+#include <ns/client.h>
+
+#ifdef HAVE_BLACKLIST
+#include <blacklist.h>
+#define blocklist blacklist
+#define blocklist_open blacklist_open
+#define blocklist_sa_r blacklist_sa_r
+#endif
+
+#ifdef HAVE_BLOCKLIST
+#include <blocklist.h>
+#endif
+
+#include <ns/pfilter.h>
+
+static struct blocklist *blstate;
+static int blenable;
+
+void
+pfilter_enable(void) {
+	blenable = 1;
+}
+
+#define TCP_CLIENT(c)  (((c)->attributes & NS_CLIENTATTR_TCP) != 0)
+
+void
+pfilter_notify(isc_result_t res, ns_client_t *client, const char *msg)
+{
+	int fd;
+
+	if (!blenable)
+		return;
+
+	if (blstate == NULL)
+		blstate = blocklist_open();
+
+	if (blstate == NULL)
+		return;
+
+	if (!TCP_CLIENT(client) && !client->peeraddr_valid)
+		return;
+
+	if ((fd = isc_nmhandle_getfd(client->handle)) == -1)
+		return;
+
+	blocklist_sa_r(blstate, 
+	    res != ISC_R_SUCCESS, fd,
+	    &client->peeraddr.type.sa, client->peeraddr.length, msg);
+}
