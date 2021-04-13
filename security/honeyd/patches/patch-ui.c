$NetBSD: patch-ui.c,v 1.1 2021/04/13 15:42:27 nia Exp $

Use libevent2 API. from FreeBSD Ports.

--- ui.c.orig	2007-05-28 06:12:52.000000000 +0000
+++ ui.c
@@ -246,7 +246,8 @@ ui_writer(int fd, short what, void *arg)
 	struct evbuffer *buffer = client->outbuf;
 	int n;
 
-	n = write(fd, buffer->buffer, buffer->off);
+	n = write(fd, evbuffer_pullup(buffer, -1),
+		  evbuffer_get_length(buffer));
 	if (n == -1) {
 		if (errno == EINTR || errno == EAGAIN)
 			goto schedule;
@@ -260,7 +261,7 @@ ui_writer(int fd, short what, void *arg)
 	evbuffer_drain(buffer, n);
 
  schedule:
-	if (buffer->off)
+	if (evbuffer_get_length(buffer))
 		event_add(&client->ev_write, NULL);
 }
 
@@ -277,8 +278,8 @@ ui_handler(int fd, short what, void *arg
 		return;
 	}
 
-	n = mybuf->off;
-	p = mybuf->buffer;
+	n = evbuffer_get_length (mybuf);
+	p = evbuffer_pullup (mybuf, -1);
 	consumed = 0;
 	while (n--) {
 		consumed++;
@@ -289,11 +290,12 @@ ui_handler(int fd, short what, void *arg
 		 */
 		if (*p == '\n') {
 			*p = '\0';
-			ui_handle_command(client->outbuf, mybuf->buffer);
+			ui_handle_command(client->outbuf,
+					  evbuffer_pullup(mybuf, -1));
 
 			evbuffer_drain(mybuf, consumed);
-			n = mybuf->off;
-			p = mybuf->buffer;
+			n = evbuffer_get_length (mybuf);
+			p = evbuffer_pullup (mybuf, -1);
 			consumed = 0;
 			continue;
 		}
