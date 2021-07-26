$NetBSD: patch-src_smtpd_pfilter.c,v 1.1 2021/07/26 15:38:10 taca Exp $

Add blocklist(3) support.

--- src/smtpd/pfilter.c.orig	2021-07-26 14:19:11.410358217 +0000
+++ src/smtpd/pfilter.c
@@ -0,0 +1,28 @@
+#include "pfilter.h"
+#include <stdio.h>	/* for NULL */
+
+#if defined(HAVE_BLOCKLIST) || defined(HAVE_BLACKLIST)
+
+#ifdef HAVE_BLOCKLIST
+#include <blocklist.h>
+#else
+#include <blacklist.h>
+#endif
+
+static struct blocklist *blstate;
+
+void
+pfilter_notify(int a, int fd)
+{
+	if (blstate == NULL)
+		blstate = blocklist_open();
+	if (blstate == NULL)
+		return;
+	(void)blocklist_r(blstate, a, fd, "smtpd");
+	if (a == 0) {
+		blocklist_close(blstate);
+		blstate = NULL;
+	}
+}
+
+#endif
