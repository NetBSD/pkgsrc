$NetBSD: patch-gio_gunixcredentialsmessage.c,v 1.3 2018/10/19 16:44:15 leot Exp $

Remove unused NetBSD case (G_CREDENTIALS_TYPE_NETBSD_UNPCBID does
not support that, LOCAL_CREDS should be probably be used instead.
Please not that before NetBSD 8.0 LOCAL_CREDS did not have an sc_pid
field making it probably not suitable as GCredentials mechanism).

--- gio/gunixcredentialsmessage.c.orig	2017-07-13 23:03:39.000000000 +0000
+++ gio/gunixcredentialsmessage.c
@@ -89,8 +89,6 @@ g_unix_credentials_message_get_msg_type 
   return SCM_CREDENTIALS;
 #elif G_CREDENTIALS_USE_FREEBSD_CMSGCRED
   return SCM_CREDS;
-#elif G_CREDENTIALS_USE_NETBSD_UNPCBID
-  return SCM_CREDS;
 #elif G_CREDENTIALS_USE_SOLARIS_UCRED
   return SCM_UCRED;
 #elif G_CREDENTIALS_UNIX_CREDENTIALS_MESSAGE_SUPPORTED
