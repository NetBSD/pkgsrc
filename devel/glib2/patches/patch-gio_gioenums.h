$NetBSD: patch-gio_gioenums.h,v 1.2 2014/10/01 12:14:42 prlw1 Exp $

gcredentials: add NetBSD support
https://bugzilla.gnome.org/show_bug.cgi?id=728256

--- gio/gioenums.h.orig	2014-03-24 18:50:42.000000000 +0000
+++ gio/gioenums.h
@@ -1354,6 +1354,7 @@ typedef enum
  * @G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED: The native credentials type is a <type>struct cmsgcred</type>.
  * @G_CREDENTIALS_TYPE_OPENBSD_SOCKPEERCRED: The native credentials type is a <type>struct sockpeercred</type>. Added in 2.30.
  * @G_CREDENTIALS_TYPE_SOLARIS_UCRED: The native credentials type is a <type>ucred_t</type>. Added in 2.40.
+ * @G_CREDENTIALS_TYPE_NETBSD_UNPCBID: The native credentials type is a <type>struct unpcbid</type>.
  *
  * Enumeration describing different kinds of native credential types.
  *
@@ -1365,7 +1366,8 @@ typedef enum
   G_CREDENTIALS_TYPE_LINUX_UCRED,
   G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED,
   G_CREDENTIALS_TYPE_OPENBSD_SOCKPEERCRED,
-  G_CREDENTIALS_TYPE_SOLARIS_UCRED
+  G_CREDENTIALS_TYPE_SOLARIS_UCRED,
+  G_CREDENTIALS_TYPE_NETBSD_UNPCBID
 } GCredentialsType;
 
 /**
