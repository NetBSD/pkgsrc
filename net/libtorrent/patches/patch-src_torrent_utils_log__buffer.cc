$NetBSD: patch-src_torrent_utils_log__buffer.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/utils/log_buffer.cc.orig	2012-03-13 12:09:16.000000000 +0000
+++ src/torrent/utils/log_buffer.cc
@@ -39,11 +39,14 @@
 #include "log_buffer.h"
 
 #include <functional>
-#include <tr1/functional>
 
 #include "globals.h"
 
+#if __cplusplus >= 201103L
+namespace tr1 { using namespace std; }
+#else
 namespace tr1 { using namespace std::tr1; }
+#endif
 
 namespace torrent {
 
