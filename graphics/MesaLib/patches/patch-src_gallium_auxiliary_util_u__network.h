$NetBSD: patch-src_gallium_auxiliary_util_u__network.h,v 1.1 2015/04/25 11:19:18 tnn Exp $

BSD has sockets, silence warning about missing implementation.

--- src/gallium/auxiliary/util/u_network.h.orig	2014-09-12 21:30:32.000000000 +0000
+++ src/gallium/auxiliary/util/u_network.h
@@ -7,7 +7,7 @@
 #if defined(PIPE_SUBSYSTEM_WINDOWS_USER)
 #  define PIPE_HAVE_SOCKETS
 #elif defined(PIPE_OS_LINUX) || defined(PIPE_OS_HAIKU) || \
-    defined(PIPE_OS_APPLE) || defined(PIPE_OS_SOLARIS)
+    defined(PIPE_OS_APPLE) || defined(PIPE_OS_SOLARIS) || defined(PIPE_OS_BSD)
 #  define PIPE_HAVE_SOCKETS
 #endif
 
