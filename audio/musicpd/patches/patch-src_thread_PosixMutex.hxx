$NetBSD: patch-src_thread_PosixMutex.hxx,v 1.2 2014/09/10 12:16:55 wiz Exp $

http://bugs.musicpd.org/view.php?id=4110

--- src/thread/PosixMutex.hxx.orig	2014-09-09 20:07:45.000000000 +0000
+++ src/thread/PosixMutex.hxx
@@ -41,7 +41,7 @@ class PosixMutex {
 	pthread_mutex_t mutex;
 
 public:
-	constexpr PosixMutex():mutex(PTHREAD_MUTEX_INITIALIZER) {}
+	PosixMutex():mutex(PTHREAD_MUTEX_INITIALIZER) {}
 
 	PosixMutex(const PosixMutex &other) = delete;
 	PosixMutex &operator=(const PosixMutex &other) = delete;
