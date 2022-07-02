$NetBSD: patch-src_pulsecore_iochannel.c,v 1.2 2022/07/02 16:44:39 ryoon Exp $

No SO_PASSCRED on macOS either.

--- src/pulsecore/iochannel.c.orig	2022-05-28 15:18:37.000000000 +0000
+++ src/pulsecore/iochannel.c
@@ -298,7 +298,7 @@ int pa_iochannel_creds_enable(pa_iochann
     pa_assert(io);
     pa_assert(io->ifd >= 0);
 
-#if !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__GNU__)
+#if !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__GNU__) && !defined(__APPLE__)
     if (setsockopt(io->ifd, SOL_SOCKET, SO_PASSCRED, &t, sizeof(t)) < 0) {
         pa_log_error("setsockopt(SOL_SOCKET, SO_PASSCRED): %s", pa_cstrerror(errno));
         return -1;
