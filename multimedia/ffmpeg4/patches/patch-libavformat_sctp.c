$NetBSD: patch-libavformat_sctp.c,v 1.1 2018/04/26 07:56:57 adam Exp $

Fix for NetBSD 7.

--- libavformat/sctp.c.orig	2018-02-12 19:57:53.000000000 +0000
+++ libavformat/sctp.c
@@ -40,6 +40,10 @@
 #include <netinet/in.h>
 #include <netinet/sctp.h>
 
+#ifndef IPPROTO_SCTP
+#define IPPROTO_SCTP 132
+#endif
+
 #include "config.h"
 
 #if HAVE_POLL_H
