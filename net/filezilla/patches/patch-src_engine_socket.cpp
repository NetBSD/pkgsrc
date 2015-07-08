$NetBSD: patch-src_engine_socket.cpp,v 1.1 2015/07/08 16:46:43 richard Exp $
upstream workaround for clash with 'struct mutex' on SunOS

--- src/engine/socket.cpp.orig	2015-03-20 04:30:04.000000000 +0000
+++ src/engine/socket.cpp
@@ -19,6 +19,7 @@
 #include "mutex.h"
 #include "socket.h"
 #ifndef __WXMSW__
+  #define mutex mutex_override // Sadly on some platforms system headers include conflicting names
   #include <sys/types.h>
   #include <sys/socket.h>
   #include <netdb.h>
@@ -29,6 +30,7 @@
   #if !defined(MSG_NOSIGNAL) && !defined(SO_NOSIGPIPE)
     #include <signal.h>
   #endif
+  #undef mutex
 #endif
 
 // Fixups needed on FreeBSD
