$NetBSD: patch-src_torrent_utils_log.cc,v 1.3 2013/09/18 16:32:05 joerg Exp $

--- src/torrent/utils/log.cc.orig	2012-03-20 15:10:16.000000000 +0000
+++ src/torrent/utils/log.cc
@@ -54,10 +54,15 @@
 #include <fstream>
 #include <functional>
 #include <memory>
+#if __cplusplus >= 201103L
+#include <memory>
+#include <functional>
+namespace tr1 { using namespace std; }
+#else
 #include <tr1/functional>
 #include <tr1/memory>
-
 namespace tr1 { using namespace std::tr1; }
+#endif
 
 namespace torrent {
 
@@ -158,6 +163,7 @@ log_group::internal_print(const HashStri
   va_list ap;
   unsigned int buffer_size = 4096;
   char buffer[buffer_size];
+  char *bufp = buffer;
   char* first = buffer;
 
   if (hash != NULL && subsystem != NULL) {
@@ -176,7 +182,7 @@ log_group::internal_print(const HashStri
   pthread_mutex_lock(&log_mutex);
   std::for_each(m_first, m_last, tr1::bind(&log_slot::operator(),
                                            tr1::placeholders::_1,
-                                           buffer,
+                                           bufp,
                                            std::distance(buffer, first),
                                            std::distance(log_groups.begin(), this)));
   if (dump_data != NULL)
@@ -238,7 +244,11 @@ void
 log_cleanup() {
   pthread_mutex_lock(&log_mutex);
 
+#if __cplusplus >= 201103L
+  log_groups.fill(log_group());
+#else
   log_groups.assign(log_group());
+#endif
   log_outputs.clear();
   log_children.clear();
 
