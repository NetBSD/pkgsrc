$NetBSD: patch-ipc_chromium_src_chrome_common_ipc__channel__posix.cc,v 1.1 2020/09/03 20:22:26 ryoon Exp $

--- ipc/chromium/src/chrome/common/ipc_channel_posix.cc.orig	2019-09-09 23:43:28.000000000 +0000
+++ ipc/chromium/src/chrome/common/ipc_channel_posix.cc
@@ -9,7 +9,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <limits.h>
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_NETBSD)
 #  include <sched.h>
 #endif
 #include <stddef.h>
@@ -700,7 +700,7 @@ bool Channel::ChannelImpl::ProcessOutgoi
           // Not an error; the sendmsg would have blocked, so return to the
           // event loop and try again later.
           break;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_NETBSD)
           // (Note: this comment is copied from https://crrev.com/86c3d9ef4fdf6;
           // see also bug 1142693 comment #73.)
           //
