$NetBSD: patch-src_listener.cpp,v 1.1 2014/12/28 17:29:42 fhajny Exp $

Recent Illumos (SunOS) platforms come with a basic epoll implementation
which is detected, but isn't good enough for rudiments.
--- src/listener.cpp.orig	2014-09-24 21:22:44.000000000 +0000
+++ src/listener.cpp
@@ -8,6 +8,10 @@
 // for FD_ZERO/FD_SET on windows
 #include <rudiments/private/winsock.h>
 
+#if defined(RUDIMENTS_HAVE_EPOLL) && defined(__sun)
+	#undef RUDIMENTS_HAVE_EPOLL
+#endif
+
 #ifdef RUDIMENTS_HAS_SSL
 	// Redhat 6.2 needs _GNU_SOURCE
 	#ifndef _GNU_SOURCE
