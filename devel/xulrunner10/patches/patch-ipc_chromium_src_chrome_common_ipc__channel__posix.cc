$NetBSD: patch-ipc_chromium_src_chrome_common_ipc__channel__posix.cc,v 1.1 2013/05/09 13:56:11 joerg Exp $

--- ipc/chromium/src/chrome/common/ipc_channel_posix.cc.orig	2013-05-05 17:41:27.000000000 +0000
+++ ipc/chromium/src/chrome/common/ipc_channel_posix.cc
@@ -12,6 +12,7 @@
 #include <sys/stat.h>
 #include <sys/un.h>
 #include <sys/uio.h>
+#include <unistd.h>
 
 #include <string>
 #include <map>
