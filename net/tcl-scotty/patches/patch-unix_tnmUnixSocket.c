$NetBSD: patch-unix_tnmUnixSocket.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- unix/tnmUnixSocket.c~	1998-10-29 14:59:07.000000000 +0100
+++ unix/tnmUnixSocket.c	2014-03-04 15:48:11.000000000 +0100
@@ -44,7 +44,7 @@
 int
 TnmSocketSendTo(s, buf, len, flags, to, tolen)
     int s;
-    char *buf;
+    const char *buf;
     int len;
     int flags;
     struct sockaddr *to;
