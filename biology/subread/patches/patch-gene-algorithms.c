$NetBSD: patch-gene-algorithms.c,v 1.1 2025/01/20 17:29:59 bacon Exp $

# Use standard compiler macros

--- gene-algorithms.c.orig	2024-07-25 00:30:10.000000000 +0000
+++ gene-algorithms.c
@@ -29,7 +29,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 
-#ifndef FREEBSD
+#ifndef __FreeBSD__
 #include <sys/timeb.h>
 #endif
 
@@ -45,7 +45,7 @@ void non_func(const char * fmt, ...)
 
 void subread_lock_release(subread_lock_t * lock)
 {
-	#ifdef MACOS
+	#ifdef __APPLE__
 	pthread_mutex_unlock(lock);
 	#else
 	pthread_spin_unlock(lock);
@@ -54,7 +54,7 @@ void subread_lock_release(subread_lock_t
 void subread_lock_occupy(subread_lock_t * lock)
 {
 
-	#ifdef MACOS
+	#ifdef __APPLE__
 	pthread_mutex_lock(lock);
 	#else
 	pthread_spin_lock(lock);
@@ -62,7 +62,7 @@ void subread_lock_occupy(subread_lock_t
 }
 
 void subread_destroy_lock(subread_lock_t * lock) {
-	#ifdef MACOS
+	#ifdef __APPLE__
 	pthread_mutex_destroy(lock);
 	#else
 	pthread_spin_destroy(lock);
@@ -71,7 +71,7 @@ void subread_destroy_lock(subread_lock_t
 
 void subread_init_lock(subread_lock_t * lock)
 {
-	#ifdef MACOS
+	#ifdef __APPLE__
 	pthread_mutex_init(lock, NULL);
 	#else
 	pthread_spin_init(lock, PTHREAD_PROCESS_PRIVATE);
@@ -1378,7 +1378,7 @@ int load_offsets(gene_offset_t* offsets
 
 double miltime(){
 	double ret;
-	#ifdef FREEBSD
+	#ifdef __FreeBSD__
 		struct timeval tp;
 		struct timezone tz;
 		tz.tz_minuteswest=0;
