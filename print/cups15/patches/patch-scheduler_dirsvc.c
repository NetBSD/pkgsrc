$NetBSD: patch-scheduler_dirsvc.c,v 1.1 2014/06/17 13:17:13 wiz Exp $

--- scheduler/dirsvc.c.orig	2011-01-22 01:07:22.000000000 +0100
+++ scheduler/dirsvc.c	2011-09-20 19:08:50.512786064 +0200
@@ -1332,7 +1332,7 @@ ldap_connect(void)
     cupsdLogMessage(CUPSD_LOG_ERROR, "LDAP bind failed with error %d: %s",
                     rc, ldap_err2string(rc));
 
-#  if defined(HAVE_LDAP_SSL) && defined (HAVE_MOZILLA_LDAP)
+#  if defined(HAVE_LDAP_SSL) && defined (HAVE_MOZILLA_LDAP) && !defined(__sun)
     if (ldap_ssl && (rc == LDAP_SERVER_DOWN || rc == LDAP_CONNECT_ERROR))
     {
       ssl_err = PORT_GetError();
