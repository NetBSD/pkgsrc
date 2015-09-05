$NetBSD: patch-scheduler_dirsvc.c,v 1.2 2015/09/05 13:03:22 jperkin Exp $

--- scheduler/dirsvc.c.orig	2012-02-11 02:05:21.000000000 +0000
+++ scheduler/dirsvc.c
@@ -1339,7 +1339,7 @@ ldap_connect(void)
     cupsdLogMessage(CUPSD_LOG_ERROR, "LDAP bind failed with error %d: %s",
                     rc, ldap_err2string(rc));
 
-#  if defined(HAVE_LDAP_SSL) && defined (HAVE_MOZILLA_LDAP)
+#  if defined(HAVE_LDAP_SSL) && defined (HAVE_MOZILLA_LDAP) && !defined(__sun)
     if (ldap_ssl && (rc == LDAP_SERVER_DOWN || rc == LDAP_CONNECT_ERROR))
     {
       ssl_err = PORT_GetError();
