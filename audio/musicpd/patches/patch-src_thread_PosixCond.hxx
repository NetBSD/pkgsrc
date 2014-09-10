$NetBSD: patch-src_thread_PosixCond.hxx,v 1.2 2014/09/10 12:16:55 wiz Exp $

http://bugs.musicpd.org/view.php?id=4110

--- src/thread/PosixCond.hxx.orig	2014-09-09 20:08:12.000000000 +0000
+++ src/thread/PosixCond.hxx
@@ -41,7 +41,7 @@ class PosixCond {
 	pthread_cond_t cond;
 
 public:
-	constexpr PosixCond():cond(PTHREAD_COND_INITIALIZER) {}
+	PosixCond():cond(PTHREAD_COND_INITIALIZER) {}
 
 	PosixCond(const PosixCond &other) = delete;
 	PosixCond &operator=(const PosixCond &other) = delete;
