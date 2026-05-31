$NetBSD: patch-extra_libevent_libevent-2.1.11-stable_kqueue.c,v 1.1 2026/05/31 10:47:48 jnemeth Exp $

--- extra/libevent/libevent-2.1.11-stable/kqueue.c.orig	2026-05-25 01:59:51.791019114 +0000
+++ extra/libevent/libevent-2.1.11-stable/kqueue.c
@@ -51,7 +51,7 @@
 /* Some platforms apparently define the udata field of struct kevent as
  * intptr_t, whereas others define it as void*.  There doesn't seem to be an
  * easy way to tell them apart via autoconf, so we need to use OS macros. */
-#if defined(EVENT__HAVE_INTTYPES_H) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__darwin__) && !defined(__APPLE__) && !defined(__CloudABI__)
+#if defined(EVENT__HAVE_INTTYPES_H) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__darwin__) && !defined(__APPLE__) && !defined(__CloudABI__) && !defined(__NetBSD__)
 #define PTR_TO_UDATA(x)	((intptr_t)(x))
 #define INT_TO_UDATA(x) ((intptr_t)(x))
 #else
