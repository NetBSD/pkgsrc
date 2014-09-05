$NetBSD: patch-gio_gioenums.h,v 1.1 2014/09/05 20:49:55 prlw1 Exp $

gcredentials: add NetBSD support
https://bugzilla.gnome.org/show_bug.cgi?id=728256

--- gio/gioenums.h.orig	2014-03-24 18:50:42.000000000 +0000
+++ gio/gioenums.h
@@ -1352,6 +1352,7 @@ typedef enum
  * @G_CREDENTIALS_TYPE_INVALID: Indicates an invalid native credential type.
  * @G_CREDENTIALS_TYPE_LINUX_UCRED: The native credentials type is a <type>struct ucred</type>.
  * @G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED: The native credentials type is a <type>struct cmsgcred</type>.
+ * @G_CREDENTIALS_TYPE_NETBSD_UNPCBID: The native credentials type is a <type>struct unpcbid</type>.
  * @G_CREDENTIALS_TYPE_OPENBSD_SOCKPEERCRED: The native credentials type is a <type>struct sockpeercred</type>. Added in 2.30.
  * @G_CREDENTIALS_TYPE_SOLARIS_UCRED: The native credentials type is a <type>ucred_t</type>. Added in 2.40.
  *
@@ -1364,6 +1365,7 @@ typedef enum
   G_CREDENTIALS_TYPE_INVALID,
   G_CREDENTIALS_TYPE_LINUX_UCRED,
   G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED,
+  G_CREDENTIALS_TYPE_NETBSD_UNPCBID,
   G_CREDENTIALS_TYPE_OPENBSD_SOCKPEERCRED,
   G_CREDENTIALS_TYPE_SOLARIS_UCRED
 } GCredentialsType;
