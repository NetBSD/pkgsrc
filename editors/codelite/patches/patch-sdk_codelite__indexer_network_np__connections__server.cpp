$NetBSD: patch-sdk_codelite__indexer_network_np__connections__server.cpp,v 1.3 2019/08/27 14:45:04 wiz Exp $

Ensure right header for timeval is included.

--- sdk/codelite_indexer/network/np_connections_server.cpp.orig	2019-05-21 17:52:21.000000000 +0300
+++ sdk/codelite_indexer/network/np_connections_server.cpp
@@ -29,6 +29,7 @@
 #ifndef __WXMSW__
 #  include <sys/types.h>
 #  include <sys/socket.h>
+#  include <sys/time.h>
 #  include <sys/un.h>
 #  include <stdio.h>
 #else
