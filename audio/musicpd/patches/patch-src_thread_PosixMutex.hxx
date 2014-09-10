$NetBSD: patch-src_thread_PosixMutex.hxx,v 1.1 2014/09/10 12:10:23 joerg Exp $

--- src/thread/PosixMutex.hxx.orig	2014-09-09 20:07:45.000000000 +0000
+++ src/thread/PosixMutex.hxx
@@ -41,7 +41,7 @@ class PosixMutex {
 	pthread_mutex_t mutex;
 
 public:
-	constexpr PosixMutex():mutex(PTHREAD_MUTEX_INITIALIZER) {}
+	PosixMutex():mutex(PTHREAD_MUTEX_INITIALIZER) {}
 
 	PosixMutex(const PosixMutex &other) = delete;
 	PosixMutex &operator=(const PosixMutex &other) = delete;
