$NetBSD: patch-gio_gunixcredentialsmessage.c,v 1.1 2014/09/05 20:49:55 prlw1 Exp $

gcredentials: add NetBSD support
https://bugzilla.gnome.org/show_bug.cgi?id=728256

--- gio/gunixcredentialsmessage.c.orig	2014-01-06 19:02:48.000000000 +0000
+++ gio/gunixcredentialsmessage.c
@@ -89,6 +89,8 @@ g_unix_credentials_message_get_msg_type 
   return SCM_CREDENTIALS;
 #elif G_CREDENTIALS_USE_FREEBSD_CMSGCRED
   return SCM_CREDS;
+#elif G_CREDENTIALS_USE_NETBSD_UNPCBID
+  return SCM_CREDS;
 #elif G_CREDENTIALS_USE_SOLARIS_UCRED
   return SCM_UCRED;
 #elif G_CREDENTIALS_UNIX_CREDENTIALS_MESSAGE_SUPPORTED
