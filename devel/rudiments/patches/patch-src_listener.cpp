$NetBSD: patch-src_listener.cpp,v 1.2 2016/07/01 16:02:12 fhajny Exp $

Recent Illumos (SunOS) platforms come with a basic epoll implementation
which is detected, but isn't good enough for rudiments.
--- src/listener.cpp.orig	2016-02-12 21:45:11.000000000 +0000
+++ src/listener.cpp
@@ -8,6 +8,10 @@
 // for FD_ZERO/FD_SET on windows
 #include <rudiments/private/winsock.h>
 
+#if defined(RUDIMENTS_HAVE_EPOLL) && defined(__sun)
+	#undef RUDIMENTS_HAVE_EPOLL
+#endif
+
 #ifdef RUDIMENTS_HAVE_STDLIB_H
 	#include <stdlib.h>
 #endif
