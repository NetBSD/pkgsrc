$NetBSD: patch-xim_connection.cpp,v 1.1 2024/04/07 04:24:23 pho Exp $

Don't use alloca(3). It's non-standard and is easily avoidable these days.
TODO: Upstream this.

--- xim/connection.cpp.orig	2024-04-07 04:05:48.893877145 +0000
+++ xim/connection.cpp
@@ -45,9 +45,6 @@
 #include <map>
 #include <unistd.h>
 #include <X11/Xatom.h>
-#ifdef HAVE_ALLOCA_H
-# include <alloca.h>
-#endif
 
 #define INIT_BUF_SIZE 1024
 #define TRANSPORT_UNIT 20
@@ -436,10 +433,9 @@ void XConnection::doSend(TxPacket *t, bo
 
     XClientMessageEvent r;
     int buflen;
-    char *buf;
 
     buflen = t->get_length();
-    buf = (char *)alloca(buflen);
+    char buf[buflen];
     t->write_to_buf((unsigned char *)buf, buflen, mByteorder);
     if (buflen < TRANSPORT_MAX) {
 	// via event
