$NetBSD: patch-agent.c,v 1.1 2017/08/16 15:18:24 jperkin Exp $

Use getpeerucred on SunOS.

--- agent.c.orig	2017-06-28 12:50:49.000000000 +0000
+++ agent.c
@@ -49,6 +49,12 @@
 #include <sys/mman.h>
 #include <errno.h>
 #include <signal.h>
+#ifdef __sun
+#define _STRUCTURED_PROC 1
+#include <ucred.h>
+#include <sys/procfs.h>
+#include <sys/ucred.h>
+#endif
 #if (defined(__unix__) || defined(unix)) && !defined(USG)
 #include <sys/param.h>
 #endif
@@ -123,6 +129,20 @@ static int agent_socket_get_cred(int fd,
 	socklen_t credlen = sizeof(struct ucred);
 	return getsockopt(fd, SOL_SOCKET, SO_PEERCRED, cred, &credlen);
 }
+#elif defined(__sun)
+static int agent_socket_get_cred(int fd, struct ucred *cred)
+{
+	ucred_t *uc;
+
+	if (getpeerucred(fd, &uc) < 0)
+		return -1;
+
+	cred->uid = ucred_geteuid(uc);
+	cred->gid = ucred_getegid(uc);
+	cred->pid = ucred_getpid(uc);
+
+	return 0;
+}
 #elif defined(__APPLE__) && defined(__MACH__) || defined(BSD)
 static int agent_socket_get_cred(int fd, struct ucred *cred)
 {
