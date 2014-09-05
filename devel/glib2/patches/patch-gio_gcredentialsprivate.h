$NetBSD: patch-gio_gcredentialsprivate.h,v 1.1 2014/09/05 20:49:55 prlw1 Exp $

gcredentials: add NetBSD support
https://bugzilla.gnome.org/show_bug.cgi?id=728256

--- gio/gcredentialsprivate.h.orig	2014-02-03 17:40:41.000000000 +0000
+++ gio/gcredentialsprivate.h
@@ -39,6 +39,14 @@
 #define G_CREDENTIALS_UNIX_CREDENTIALS_MESSAGE_SUPPORTED 1
 #define G_CREDENTIALS_SPOOFING_SUPPORTED 1
 
+#elif defined(__NetBSD__)
+#define G_CREDENTIALS_SUPPORTED 1
+#define G_CREDENTIALS_USE_NETBSD_UNPCBID 1
+#define G_CREDENTIALS_NATIVE_TYPE G_CREDENTIALS_TYPE_NETBSD_UNPCBID
+#define G_CREDENTIALS_NATIVE_SIZE (sizeof (struct unpcbid))
+#undef G_CREDENTIALS_UNIX_CREDENTIALS_MESSAGE_SUPPORTED
+#define G_CREDENTIALS_SPOOFING_SUPPORTED 1
+
 #elif defined(__OpenBSD__)
 #define G_CREDENTIALS_SUPPORTED 1
 #define G_CREDENTIALS_USE_OPENBSD_SOCKPEERCRED 1
