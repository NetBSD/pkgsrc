$NetBSD: patch-src_ifd_ifdhandler.c,v 1.1 2026/02/03 08:39:15 wiz Exp $

Fix build with gcc 14.
https://github.com/OpenSC/openct/pull/12

--- src/ifd/ifdhandler.c.orig	2009-02-26 08:58:12.000000000 +0000
+++ src/ifd/ifdhandler.c
@@ -236,7 +236,7 @@ static void ifdhandler_run(ifd_reader_t * reader)
 		sock->fd = -1;
 	}
 	else {
-		sock->fd = ifd_get_eventfd(reader, &sock->events);
+		sock->fd = ifd_get_eventfd(reader, (short int *)&sock->events);
 	}
 	if (sock->fd == -1) {
 		ifd_debug(1, "events inactive for reader %s", reader->name);
