$NetBSD: patch-atomicio.c,v 1.6 2026/10/07 15:22:05 he Exp $

Fix for PR#60563.

--- atomicio.c.orig	2026-09-22 07:42:45.683284535 +0000
+++ atomicio.c
@@ -51,7 +51,7 @@ atomicio6(ssize_t (*f) (int, void *, siz
 	struct pollfd pfd;
 
 	pfd.fd = fd;
-	pfd.events = f == read ? POLLIN : POLLOUT;
+	pfd.events = f == vwrite ? POLLOUT : POLLIN;
 	while (n > pos) {
 		res = (f) (fd, s + pos, n - pos);
 		switch (res) {
