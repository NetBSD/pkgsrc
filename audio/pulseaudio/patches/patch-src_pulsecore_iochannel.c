$NetBSD: patch-src_pulsecore_iochannel.c,v 1.1 2021/09/16 13:02:34 schmonz Exp $

No SO_PASSCRED on macOS either.

--- src/pulsecore/iochannel.c.orig	2021-07-27 20:02:27.000000000 +0000
+++ src/pulsecore/iochannel.c
@@ -298,7 +298,7 @@ int pa_iochannel_creds_enable(pa_iochann
     pa_assert(io);
     pa_assert(io->ifd >= 0);
 
-#if !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__)
+#if !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__APPLE__)
     if (setsockopt(io->ifd, SOL_SOCKET, SO_PASSCRED, &t, sizeof(t)) < 0) {
         pa_log_error("setsockopt(SOL_SOCKET, SO_PASSCRED): %s", pa_cstrerror(errno));
         return -1;
