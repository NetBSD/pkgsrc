$NetBSD: patch-include_asterisk_lock.h,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- include/asterisk/lock.h.orig	2021-03-04 16:46:08.000000000 +0000
+++ include/asterisk/lock.h
@@ -616,6 +616,17 @@ static void  __attribute__((destructor))
  */
 #define SCOPED_CHANNELLOCK(varname, chan) SCOPED_LOCK(varname, (chan), ast_channel_lock, ast_channel_unlock)
 
+#undef pthread_mutex_lock
+#undef pthread_mutex_unlock
+#undef pthread_mutex_trylock
+#undef pthread_mutex_init
+#undef pthread_mutex_destroy
+#undef pthread_cond_init
+#undef pthread_cond_destroy
+#undef pthread_cond_signal
+#undef pthread_cond_broadcast
+#undef pthread_cond_wait
+#undef pthread_cond_timedwait
 #ifndef __CYGWIN__	/* temporary disabled for cygwin */
 #define pthread_mutex_t		use_ast_mutex_t_instead_of_pthread_mutex_t
 #define pthread_cond_t		use_ast_cond_t_instead_of_pthread_cond_t
@@ -636,7 +647,7 @@ static void  __attribute__((destructor))
 
 #define gethostbyname __gethostbyname__is__not__reentrant__use__ast_gethostbyname__instead__
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__DragonFly__)
 #define pthread_create __use_ast_pthread_create_instead__
 #endif
 
