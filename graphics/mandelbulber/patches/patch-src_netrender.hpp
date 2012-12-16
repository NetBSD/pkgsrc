$NetBSD: patch-src_netrender.hpp,v 1.1 2012/12/16 16:10:56 ryoon Exp $

* Fix build on *BSD

--- src/netrender.hpp.orig	2012-12-02 16:22:54.000000000 +0000
+++ src/netrender.hpp
@@ -23,6 +23,8 @@
 	#include <netdb.h>
 #endif
 
+#include <netinet/in.h>
+
 #include <errno.h>
 #include <unistd.h>
 #include <vector>
