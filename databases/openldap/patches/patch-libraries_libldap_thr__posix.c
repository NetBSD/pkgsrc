$NetBSD: patch-libraries_libldap_thr__posix.c,v 1.2 2025/07/09 09:18:01 jperkin Exp $

Fix for systems lacking pthread_attr_setstacksize().
Correct includes for thr_yield().

--- libraries/libldap/thr_posix.c.orig	2025-05-22 17:56:21.000000000 +0000
+++ libraries/libldap/thr_posix.c
@@ -25,6 +25,7 @@
 #endif
 
 #include <ac/errno.h>
+#include <ac/unistd.h>
 
 #ifdef REPLACE_BROKEN_YIELD
 #ifndef HAVE_NANOSLEEP
@@ -38,6 +39,9 @@
 #define LDAP_THREAD_RDWR_IMPLEMENTATION
 #include "ldap_thr_debug.h"	 /* May rename the symbols defined below */
 #include <signal.h>			 /* For pthread_kill() */
+#ifdef HAVE_THR_YIELD
+#include <thread.h>
+#endif
 
 extern int ldap_int_stackguard;
 
@@ -161,11 +165,13 @@ ldap_pvt_thread_create( ldap_pvt_thread_
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
