$NetBSD: patch-ipc_chromium_src_base_message__pump__libevent.cc,v 1.1 2013/05/09 13:56:11 joerg Exp $

--- ipc/chromium/src/base/message_pump_libevent.cc.orig	2013-05-05 17:38:57.000000000 +0000
+++ ipc/chromium/src/base/message_pump_libevent.cc
@@ -6,6 +6,7 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <unistd.h>
 
 #include "eintr_wrapper.h"
 #include "base/logging.h"
