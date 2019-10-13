--- /dev/null	2016-01-22 17:30:55.000000000 -0500
+++ src/pfilter.c	2016-01-22 16:37:55.000000000 -0500
--- src/pfilter.c.orig	2019-10-13 19:47:58.437871822 +0000
+++ src/pfilter.c
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
