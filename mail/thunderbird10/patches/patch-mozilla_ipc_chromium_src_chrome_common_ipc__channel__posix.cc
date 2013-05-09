$NetBSD: patch-mozilla_ipc_chromium_src_chrome_common_ipc__channel__posix.cc,v 1.1 2013/05/09 13:59:47 joerg Exp $

--- mozilla/ipc/chromium/src/chrome/common/ipc_channel_posix.cc.orig	2013-01-05 14:22:10.000000000 +0000
+++ mozilla/ipc/chromium/src/chrome/common/ipc_channel_posix.cc
@@ -12,6 +12,7 @@
 #include <sys/stat.h>
 #include <sys/un.h>
 #include <sys/uio.h>
+#include <unistd.h>
 
 #include <string>
 #include <map>
