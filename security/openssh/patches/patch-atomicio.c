$NetBSD: patch-atomicio.c,v 1.4 2026/09/22 08:03:59 he Exp $

Remove no-longer-needed BROKEN_READ_COMPARISON code, to mirror

  https://github.com/openssh/openssh-portable/commit/a765b86d

ref. mailing list thread at

  https://lists.mindrot.org/pipermail/openssh-unix-dev/2026-September/042758.html

--- atomicio.c.orig	2026-09-22 07:42:45.683284535 +0000
+++ atomicio.c
@@ -51,11 +51,7 @@ atomicio6(ssize_t (*f) (int, void *, siz
 	struct pollfd pfd;
 
 	pfd.fd = fd;
-#ifndef BROKEN_READ_COMPARISON
 	pfd.events = f == read ? POLLIN : POLLOUT;
-#else
-	pfd.events = POLLIN|POLLOUT;
-#endif
 	while (n > pos) {
 		res = (f) (fd, s + pos, n - pos);
 		switch (res) {
