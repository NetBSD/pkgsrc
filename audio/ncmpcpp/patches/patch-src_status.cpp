$NetBSD: patch-src_status.cpp,v 1.1 2022/04/18 13:33:28 nia Exp $

Add missing header for socket(2).
Fix building on illumos.

--- src/status.cpp.orig	2021-01-24 15:50:24.000000000 +0000
+++ src/status.cpp
@@ -21,6 +21,7 @@
 #include <boost/date_time/posix_time/posix_time.hpp>
 #include <netinet/tcp.h>
 #include <netinet/in.h>
+#include <sys/socket.h>
 
 #include "curses/menu_impl.h"
 #include "screens/browser.h"
