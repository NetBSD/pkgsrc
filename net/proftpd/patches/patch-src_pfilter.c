$NetBSD: patch-src_pfilter.c,v 1.3 2021/10/16 19:46:42 tm Exp $

Add pfilter objects.

--- /dev/null	Fri Oct 15 10:32:05 2021
+++ src/pfilter.c	Fri Oct 15 10:32:05 2021
@@ -0,0 +1,41 @@
+#include "pfilter.h"
+#include "conf.h"
+#include "privs.h"
+#ifdef HAVE_BLACKLIST
+#include <blacklist.h>
+#endif
+
+static struct blacklist *blstate;
+
+void
+pfilter_init(void)
+{
+#ifdef HAVE_BLACKLIST
+	if (blstate == NULL)
+		blstate = blacklist_open();
+#endif
+}
+
+void
+pfilter_notify(int a)
+{
+#ifdef HAVE_BLACKLIST
+	conn_t *c = session.c;
+	int fd;
+
+	if (c == NULL)
+		return;
+	if (c->rfd != -1)
+		fd = c->rfd;
+	else if (c->wfd != -1)
+		fd = c->wfd;
+	else
+		return;
+
+	if (blstate == NULL)
+		pfilter_init();
+	if (blstate == NULL)
+		return;
+	(void)blacklist_r(blstate, a, fd, "proftpd");
+#endif
+}
