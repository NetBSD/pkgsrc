$NetBSD: patch-src_lib_connection.h,v 1.1 2016/11/12 16:12:08 taca Exp $

* Require header for timeval structure.

--- src/lib/connection.h.orig	2016-10-27 12:26:28.000000000 +0000
+++ src/lib/connection.h
@@ -3,6 +3,10 @@
 
 #include "net.h"
 
+#ifdef HAVE_SYS_TIME_H
+#include <sys/time.h>
+#endif
+
 struct connection;
 
 enum connection_behavior {
