$NetBSD: patch-src_unix_darwin-proctitle.c,v 1.1 2022/01/28 21:13:10 schmonz Exp $

Apply MacPorts patch-libuv-legacy.diff for pre-10.7 platforms.

--- src/unix/darwin-proctitle.c.orig	2022-01-04 14:18:00.000000000 +0000
+++ src/unix/darwin-proctitle.c
@@ -41,9 +41,11 @@ static int uv__pthread_setname_np(const 
   strncpy(namebuf, name, sizeof(namebuf) - 1);
   namebuf[sizeof(namebuf) - 1] = '\0';
 
+#if TARGET_OS_IPHONE || MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
   err = pthread_setname_np(namebuf);
   if (err)
     return UV__ERR(err);
+#endif
 
   return 0;
 }
