$NetBSD: patch-ipc_chromium_src_chrome_common_ipc__channel__posix.cc,v 1.1 2020/03/13 17:59:27 wiz Exp $

In the original code there is a special case for Darwin whose
sendmsg(2) fails with EMSGSIZE when a fd is to be transferred but
there isn't enough space in the send buffer. It turned out the same
applies to NetBSD too. It may affect other BSD kernels as well, but we
haven't tested them.

Please remove this patch when the upstream issue is resolved:
https://bugzilla.mozilla.org/show_bug.cgi?id=1553389

--- ipc/chromium/src/chrome/common/ipc_channel_posix.cc.orig	2019-05-10 06:37:41.200812057 +0000
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
@@ -699,7 +699,7 @@ bool Channel::ChannelImpl::ProcessOutgoi
           // Not an error; the sendmsg would have blocked, so return to the
           // event loop and try again later.
           break;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_NETBSD)
           // (Note: this comment is copied from https://crrev.com/86c3d9ef4fdf6;
           // see also bug 1142693 comment #73.)
           //
