$NetBSD: patch-lib_isc_app.c,v 1.1 2021/10/24 06:40:28 taca Exp $

* Take from NetBSD base.

--- lib/isc/app.c.orig	2021-09-07 09:37:05.000000000 +0000
+++ lib/isc/app.c
@@ -162,6 +162,8 @@ isc_app_ctxstart(isc_appctx_t *ctx) {
 	 * blocked by default, ensuring that only the thread that calls
 	 * sigwait() for them will get those signals.
 	 */
+	if (isc_bind9) {
+
 	if (sigemptyset(&sset) != 0 || sigaddset(&sset, SIGHUP) != 0 ||
 	    sigaddset(&sset, SIGINT) != 0 || sigaddset(&sset, SIGTERM) != 0)
 	{
@@ -176,6 +178,8 @@ isc_app_ctxstart(isc_appctx_t *ctx) {
 				"isc_app_start() pthread_sigmask: %s", strbuf);
 	}
 
+	}
+
 #endif /* WIN32 */
 
 	return (ISC_R_SUCCESS);
