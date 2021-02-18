$NetBSD: patch-tools_xenstore_xenstored_core.c,v 1.1.2.2 2021/02/18 05:21:21 spz Exp $

On error, don't keep socket connection in ignored state but close them.
When the remote end of a socket is closed, xenstored will flag it as an
error and switch the connection to ignored. But on some OSes (e.g.
NetBSD), poll(2) will return only POLLIN in this case, so sockets in ignored
state will stay open forever in xenstored (and it will loop with CPU 100%
busy).

Signed-off-by: Manuel Bouyer <bouyer@netbsd.org>
Fixes: d2fa370d3ef9cbe22d7256c608671cdcdf6e0083
---
 tools/xenstore/xenstored_core.c | 3 +++
 1 file changed, 3 insertions(+)

diff --git a/tools/xenstore/xenstored_core.c b/tools/xenstore/xenstored_core.c
index 1ab6f162cb..0fea598352 100644
--- tools/xenstore/xenstored_core.c.orig
+++ tools/xenstore/xenstored_core.c
@@ -1440,6 +1440,9 @@ static void ignore_connection(struct connection *conn)
 
 	talloc_free(conn->in);
 	conn->in = NULL;
+	/* if this is a socket connection, drop it now */
+	if (conn->fd >= 0)
+		talloc_free(conn);
 }
 
 static const char *sockmsg_string(enum xsd_sockmsg_type type)
