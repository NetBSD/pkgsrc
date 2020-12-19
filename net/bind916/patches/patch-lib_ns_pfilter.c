$NetBSD: patch-lib_ns_pfilter.c,v 1.3 2020/12/19 16:41:36 taca Exp $

* Based on NetBSD, add support for blocklist(blacklist).

--- lib/ns/pfilter.c.orig	2020-12-17 07:42:44.024890144 +0000
+++ lib/ns/pfilter.c
@@ -0,0 +1,59 @@
+
+#include "config.h"
+
+#include <isc/platform.h>
+#include <isc/util.h>
+#include <ns/types.h>
+#include <ns/client.h>
+
+#ifdef HAVE_BLACKLIST_H
+#include <blacklist.h>
+#define blocklist blacklist
+#define blocklist_open blacklist_open
+#define blocklist_sa_r blacklist_sa_r
+#endif
+
+#ifdef HAVE_BLOCKLIST_H
+#include <blocklist.h>
+#endif
+
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
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
+
+#endif
