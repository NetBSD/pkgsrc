$NetBSD: patch-libraries_librewrite_session.c,v 1.1 2014/05/09 08:12:00 tron Exp $

Fix for CVE-2013-4449 taken from the OpenLDA GIT repository:

http://www.openldap.org/devel/gitweb.cgi?p=openldap.git;a=commit;h=59688044386dfeee0c837a15133f4e878f1bb661

--- libraries/librewrite/session.c.orig	2014-01-25 13:36:15.000000000 +0000
+++ libraries/librewrite/session.c	2014-05-09 09:03:51.000000000 +0100
@@ -161,6 +161,7 @@
 #ifdef USE_REWRITE_LDAP_PVT_THREADS
 	if ( session ) {
 		ldap_pvt_thread_mutex_lock( &session->ls_mutex );
+		session->ls_count++;
 	}
 	ldap_pvt_thread_rdwr_runlock( &info->li_cookies_mutex );
 #endif /* USE_REWRITE_LDAP_PVT_THREADS */
@@ -178,6 +179,7 @@
 )
 {
 	assert( session != NULL );
+	session->ls_count--;
 	ldap_pvt_thread_mutex_unlock( &session->ls_mutex );
 }
 
