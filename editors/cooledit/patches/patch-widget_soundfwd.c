$NetBSD: patch-widget_soundfwd.c,v 1.1 2026/10/20 20:57:33 ktnb Exp $

No sys/sysmacros.h on NetBSD

--- widget/soundfwd.c.orig	2026-10-20 19:25:40.368169410 +0000
+++ widget/soundfwd.c
@@ -44,7 +44,7 @@
 #ifndef MSWIN
 #include <sys/socket.h>
 #include <sys/signal.h>
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <sys/sysmacros.h>
 #endif
 #include <netinet/in.h>
