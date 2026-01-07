$NetBSD: patch-opal_mca_event_libevent2022_libevent_kqueue.c,v 1.1 2026/01/07 18:27:38 adam Exp $

Support NetBSD.

--- opal/mca/event/libevent2022/libevent/kqueue.c.orig	2025-12-22 06:22:24.942783208 +0000
+++ opal/mca/event/libevent2022/libevent/kqueue.c
@@ -49,7 +49,7 @@
 /* Some platforms apparently define the udata field of struct kevent as
  * intptr_t, whereas others define it as void*.  There doesn't seem to be an
  * easy way to tell them apart via autoconf, so we need to use OS macros. */
-#if defined(_EVENT_HAVE_INTTYPES_H) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__darwin__) && !defined(__APPLE__)
+#if defined(_EVENT_HAVE_INTTYPES_H) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__darwin__) && !defined(__APPLE__) && !defined(__NetBSD__)
 #define PTR_TO_UDATA(x)	((intptr_t)(x))
 #define INT_TO_UDATA(x) ((intptr_t)(x))
 #else
