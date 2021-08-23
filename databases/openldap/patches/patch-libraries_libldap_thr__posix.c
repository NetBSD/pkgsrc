$NetBSD: patch-libraries_libldap_thr__posix.c,v 1.1 2021/08/23 09:58:58 adam Exp $

Fix for systems lacking pthread_attr_setstacksize().

--- libraries/libldap/thr_posix.c.orig	2021-07-27 17:44:47.000000000 +0000
+++ libraries/libldap/thr_posix.c
@@ -25,6 +25,7 @@
 #endif
 
 #include <ac/errno.h>
+#include <ac/unistd.h>
 
 #ifdef REPLACE_BROKEN_YIELD
 #ifndef HAVE_NANOSLEEP
@@ -161,11 +162,13 @@ ldap_pvt_thread_create( ldap_pvt_thread_
 #endif
 
 #ifdef LDAP_PVT_THREAD_SET_STACK_SIZE
+#ifdef _POSIX_THREAD_ATTR_STACKSIZE
 	/* this should be tunable */
 	pthread_attr_setstacksize( &attr, LDAP_PVT_THREAD_STACK_SIZE );
 	if ( ldap_int_stackguard )
 		pthread_attr_setguardsize( &attr, LDAP_PVT_THREAD_STACK_SIZE );
 #endif
+#endif
 
 #if HAVE_PTHREADS > 5
 	detach = detach ? PTHREAD_CREATE_DETACHED : PTHREAD_CREATE_JOINABLE;
