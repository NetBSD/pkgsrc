$NetBSD: patch-atomicio.c,v 1.1.2.2 2011/08/23 07:17:45 tron Exp $

Avoid SSP side effect:
http://mail-index.netbsd.org/source-changes/2011/08/01/msg025290.html

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
