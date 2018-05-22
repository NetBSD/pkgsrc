$NetBSD: patch-src_lib_connection.h,v 1.2 2018/05/22 20:49:45 triaxx Exp $

* Require header for timeval structure.

--- src/lib/connection.h.orig	2018-03-20 10:15:40.000000000 +0000
+++ src/lib/connection.h
@@ -3,6 +3,10 @@
 
 #include "net.h"
 
+#ifdef HAVE_SYS_TIME_H
+#include <sys/time.h>
+#endif
+
 struct ioloop;
 struct connection;
 
