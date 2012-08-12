$NetBSD: patch-include_konoha1_konoha__t.h,v 1.2 2012/08/12 11:24:00 marino Exp $

* Try to support *BSD
* FreeBSD and DragonFly have NSIG exposed

--- include/konoha1/konoha_t.h.orig	2012-03-07 06:52:14.000000000 +0000
+++ include/konoha1/konoha_t.h
@@ -1041,6 +1041,14 @@ typedef struct kcontext_t {
 	void                           *siginfo;
 #if defined(K_USING_MINGW_)
 #define K_SIGNAL_MAX NSIG
+#elif defined(K_USING_MACOSX_)
+#define K_SIGNAL_MAX _POSIX_SIGQUEUE_MAX
+#elif defined(K_USING_BSD_)
+#ifdef __NetBSD__
+#define K_SIGNAL_MAX _NSIG /* I am not sure. */
+#else
+#define K_SIGNAL_MAX NSIG
+#endif
 #else
 #define K_SIGNAL_MAX _POSIX_SIGQUEUE_MAX
 #endif
