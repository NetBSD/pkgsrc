$NetBSD: patch-src_threading.c,v 1.1 2020/07/11 16:15:09 nia Exp $

NetBSD support.

--- src/threading.c.orig	2018-11-30 12:28:50.000000000 +0000
+++ src/threading.c
@@ -886,9 +886,16 @@ void THREAD_SET_PRIORITY( int prio)
 
 void THREAD_SET_AFFINITY( unsigned int aff)
 {
-	cpu_set_t cpuset;
 	int bit = 0;
+#ifdef __NetBSD__
+	cpuset_t *cpuset = cpuset_create();
+	if( cpuset == NULL)
+		_PT_FAIL( errno, "cpuset_create", __FILE__, __LINE__-2 );
+#define CPU_SET(b, s) cpuset_set(b, *(s))
+#else
+	cpu_set_t cpuset;
 	CPU_ZERO( &cpuset);
+#endif
 	while( aff != 0)
 	{
 		if( aff & 1)
@@ -900,6 +907,9 @@ void THREAD_SET_AFFINITY( unsigned int a
 	}
 #ifdef __ANDROID__
 	PT_CALL( sched_setaffinity( pthread_self(), sizeof(cpu_set_t), &cpuset));
+#elif defined(__NetBSD__)
+	PT_CALL( pthread_setaffinity_np( pthread_self(), cpuset_size(cpuset), cpuset));
+	cpuset_destroy( cpuset);
 #else
 	PT_CALL( pthread_setaffinity_np( pthread_self(), sizeof(cpu_set_t), &cpuset));
 #endif
@@ -996,8 +1006,10 @@ bool_t THREAD_WAIT( THREAD_T *ref, doubl
 	{
 		// exact API to set the thread name is platform-dependant
 		// if you need to fix the build, or if you know how to fill a hole, tell me (bnt.germain@gmail.com) so that I can submit the fix in github.
-#if defined PLATFORM_BSD
+#if defined PLATFORM_BSD && !defined __NetBSD__
 		pthread_set_name_np( pthread_self(), _name);
+#elif defined PLATFORM_BSD && defined __NetBSD__
+		pthread_setname_np( pthread_self(), "%s", (void *)_name);
 #elif defined PLATFORM_LINUX
 	#if LINUX_USE_PTHREAD_SETNAME_NP
 		pthread_setname_np( pthread_self(), _name);
