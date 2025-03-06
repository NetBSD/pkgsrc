$NetBSD: patch-src_syncterm_conn__pty.c,v 1.1 2025/03/06 04:33:36 vins Exp $

cfsetspeed() is a BSD extension.

--- src/syncterm/conn_pty.c.orig	2025-03-05 20:26:19.553091505 +0000
+++ src/syncterm/conn_pty.c
@@ -487,7 +487,8 @@ pty_connect(struct bbslist *bbs)
 #ifdef VSTATUS
 	ts.c_cc[VSTATUS] = CSTATUS;
 #endif
-	cfsetspeed(&ts, 115200);
+	cfsetispeed(&ts, 115200);
+	cfsetospeed(&ts, 115200);
 
 	get_term_win_size(&cols, &rows, &pixelc, &pixelr, &bbs->nostatus);
 	ws.ws_col = cols;
