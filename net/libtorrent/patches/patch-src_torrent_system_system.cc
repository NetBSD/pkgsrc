$NetBSD: patch-src_torrent_system_system.cc,v 1.1 2026/07/18 18:28:15 gdt Exp $

system.cc uses AF_INET.  POSIX says that constants are defined in sys/socket:

  https://pubs.opengroup.org/onlinepubs/9799919799/functions/socket.html

Not yet reported upstream.

--- src/torrent/system/system.cc.orig	2026-07-18 18:18:35.886055891 +0000
+++ src/torrent/system/system.cc
@@ -4,6 +4,8 @@
 #include <cstdio>
 #include <netdb.h>
 
+#include <sys/socket.h>
+
 #include "torrent/exceptions.h"
 #include "torrent/system/callbacks.h"
 #include "torrent/system/thread.h"
