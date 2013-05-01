$NetBSD: patch-atomicio.c,v 1.2 2013/05/01 19:58:26 imil Exp $

Check for vwrite instead of read to avoid read being renamed by SSP issues

--- atomicio.c.orig	2010-09-24 12:15:11.000000000 +0000
+++ atomicio.c
@@ -57,7 +57,11 @@ atomicio6(ssize_t (*f) (int, void *, siz
 	struct pollfd pfd;
 
 	pfd.fd = fd;
-	pfd.events = f == read ? POLLIN : POLLOUT;
+	/*
+	 * check for vwrite instead of read to avoid read being renamed
+	 * by SSP issues
+	 */
+	pfd.events = f == vwrite ? POLLOUT : POLLIN;
 	while (n > pos) {
 		res = (f) (fd, s + pos, n - pos);
 		switch (res) {
