$NetBSD: patch-src_kqueue.cpp,v 1.1 2019/12/19 22:21:57 joerg Exp $

--- src/kqueue.cpp.orig	2019-12-19 14:32:14.474104176 +0000
+++ src/kqueue.cpp
@@ -46,10 +46,15 @@
 #include "i_poll_events.hpp"
 #include "likely.hpp"
 
-//  NetBSD defines (struct kevent).udata as intptr_t, everyone else
-//  as void *.
+//  NetBSD before 9.99.15 defined (struct kevent).udata as intptr_t,
+//  everyone else as void *.
 #if defined ZMQ_HAVE_NETBSD
-#define kevent_udata_t intptr_t
+#  include <sys/param.h>
+#  if __NetBSD_Version__ < 999001500
+#  define kevent_udata_t intptr_t
+#  else
+#  define kevent_udata_t void *
+#  endif
 #else
 #define kevent_udata_t void *
 #endif
