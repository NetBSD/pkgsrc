$NetBSD: patch-mozilla_ipc_chromium_src_base_message__pump__libevent.cc,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/ipc/chromium/src/base/message_pump_libevent.cc.orig	2013-10-23 22:09:00.000000000 +0000
+++ mozilla/ipc/chromium/src/base/message_pump_libevent.cc
@@ -16,7 +16,7 @@
 #include "base/scoped_ptr.h"
 #include "base/time.h"
 #include "nsDependentSubstring.h"
-#include "third_party/libevent/event.h"
+#include "event.h"
 
 // Lifecycle of struct event
 // Libevent uses two main data structures:
