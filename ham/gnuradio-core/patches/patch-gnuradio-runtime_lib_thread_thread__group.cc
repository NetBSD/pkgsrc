$NetBSD: patch-gnuradio-runtime_lib_thread_thread__group.cc,v 1.1 2022/10/09 07:56:51 adam Exp $

Fix building.

--- gnuradio-runtime/lib/thread/thread_group.cc.orig	2022-10-08 17:46:38.551298711 +0000
+++ gnuradio-runtime/lib/thread/thread_group.cc
@@ -14,6 +14,7 @@
 
 #include <gnuradio/thread/thread_group.h>
 #include <cassert>
+#include <mutex>
 #include <memory>
 
 namespace gr {
