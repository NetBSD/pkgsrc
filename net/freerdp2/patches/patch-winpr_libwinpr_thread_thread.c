$NetBSD: patch-winpr_libwinpr_thread_thread.c,v 1.1 2023/01/19 08:01:37 markd Exp $

NetBSD9 and some others dont define ENOTRECOVERABLE

--- winpr/libwinpr/thread/thread.c.orig	2022-11-16 14:06:20.000000000 +0000
+++ winpr/libwinpr/thread/thread.c
@@ -272,7 +272,9 @@ static BOOL mux_condition_bundle_wait(mu
 			WLog_ERR(TAG, "failed to wait for %s [%s]", name, strerror(r));
 			switch (r)
 			{
+#ifdef ENOTRECOVERABLE
 				case ENOTRECOVERABLE:
+#endif
 				case EPERM:
 				case ETIMEDOUT:
 				case EINVAL:
