$NetBSD: patch-lib_isc_app.c,v 1.1 2022/12/11 01:57:55 sekiya Exp $

* Take from NetBSD base.

--- lib/isc/app.c.orig	2022-11-08 07:17:42.048257952 +0900
+++ lib/isc/app.c	2022-12-10 10:44:08.372064499 +0900
@@ -120,6 +120,8 @@
 	 * blocked by default, ensuring that only the thread that calls
 	 * sigwait() for them will get those signals.
 	 */
+	if (isc_bind9) {
+
 	if (sigemptyset(&sset) != 0 || sigaddset(&sset, SIGHUP) != 0 ||
 	    sigaddset(&sset, SIGINT) != 0 || sigaddset(&sset, SIGTERM) != 0)
 	{
@@ -130,6 +132,8 @@
 		FATAL_SYSERROR(presult, "pthread_sigmask()");
 	}
 
+	}
+
 	return (ISC_R_SUCCESS);
 }
 
