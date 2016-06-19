$NetBSD: patch-sdk_codelite__indexer_network_np__connections__server.cpp,v 1.1 2016/06/19 23:01:33 joerg Exp $

--- sdk/codelite_indexer/network/np_connections_server.cpp.orig	2016-06-19 20:52:21.634007785 +0000
+++ sdk/codelite_indexer/network/np_connections_server.cpp
@@ -29,6 +29,7 @@
 #ifndef __WXMSW__
 #  include <sys/types.h>
 #  include <sys/socket.h>
+#  include <sys/time.h>
 #  include <sys/un.h>
 #  include <stdio.h>
 #else
