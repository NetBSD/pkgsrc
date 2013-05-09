$NetBSD: patch-mozilla_ipc_chromium_src_base_message__pump__libevent.cc,v 1.1 2013/05/09 13:59:47 joerg Exp $

--- mozilla/ipc/chromium/src/base/message_pump_libevent.cc.orig	2013-01-05 14:22:10.000000000 +0000
+++ mozilla/ipc/chromium/src/base/message_pump_libevent.cc
@@ -6,6 +6,7 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <unistd.h>
 
 #include "eintr_wrapper.h"
 #include "base/logging.h"
