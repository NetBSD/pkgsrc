$NetBSD: patch-storage_tokudb_ft-index_portability_toku__pthread.h,v 1.1 2015/04/16 20:20:15 ryoon Exp $

--- storage/tokudb/ft-index/portability/toku_pthread.h.orig	2015-02-13 12:07:05.000000000 +0000
+++ storage/tokudb/ft-index/portability/toku_pthread.h
@@ -142,7 +142,7 @@ typedef struct toku_mutex_aligned {
 #endif
 
 // Darwin doesn't provide adaptive mutexes
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__NetBSD__)
 # define TOKU_MUTEX_ADAPTIVE PTHREAD_MUTEX_DEFAULT
 # if TOKU_PTHREAD_DEBUG
 #  define TOKU_ADAPTIVE_MUTEX_INITIALIZER { .pmutex = PTHREAD_MUTEX_INITIALIZER, .owner = 0, .locked = false, .valid = true }
