$NetBSD: patch-widget_xwinfwd.c,v 1.1 2026/10/20 20:57:33 ktnb Exp $

Not sys/sysmacros.h on NetBSD

--- widget/xwinfwd.c.orig	2026-10-20 19:24:25.694437512 +0000
+++ widget/xwinfwd.c
@@ -44,7 +44,7 @@
 #ifndef MSWIN
 #include <sys/socket.h>
 #include <sys/signal.h>
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <sys/sysmacros.h>
 #endif
 #include <netinet/in.h>
