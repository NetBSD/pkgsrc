$NetBSD: patch-vowpalwabbit_sender.cc,v 1.1 2016/09/18 07:08:19 dholland Exp $

Use standard headers.

--- vowpalwabbit/sender.cc~	2016-06-21 18:37:43.000000000 +0000
+++ vowpalwabbit/sender.cc
@@ -13,6 +13,8 @@
 #   define SHUT_RDWR SD_BOTH
 #endif
 #else
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netdb.h>
 #endif
 #include "io_buf.h"
