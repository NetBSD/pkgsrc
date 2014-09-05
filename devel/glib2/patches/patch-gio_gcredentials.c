$NetBSD: patch-gio_gcredentials.c,v 1.1 2014/09/05 20:49:55 prlw1 Exp $

gcredentials: add NetBSD support
https://bugzilla.gnome.org/show_bug.cgi?id=728256

--- gio/gcredentials.c.orig	2014-02-03 17:40:41.000000000 +0000
+++ gio/gcredentials.c
@@ -59,6 +59,9 @@
  * credential type is a struct cmsgcred. This corresponds
  * to %G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED.
  *
+ * On NetBSD, the native credential type is a struct unpcbid.
+ * This corresponds to %G_CREDENTIALS_TYPE_NETBSD_UNPCBID.
+ *
  * On OpenBSD, the native credential type is a struct sockpeercred.
  * This corresponds to %G_CREDENTIALS_TYPE_OPENBSD_SOCKPEERCRED.
  *
@@ -84,6 +87,8 @@ struct _GCredentials
   struct ucred native;
 #elif G_CREDENTIALS_USE_FREEBSD_CMSGCRED
   struct cmsgcred native;
+#elif G_CREDENTIALS_USE_NETBSD_UNPCBID
+  struct unpcbid native;
 #elif G_CREDENTIALS_USE_OPENBSD_SOCKPEERCRED
   struct sockpeercred native;
 #elif G_CREDENTIALS_USE_SOLARIS_UCRED
@@ -145,6 +150,10 @@ g_credentials_init (GCredentials *creden
   credentials->native.cmcred_pid  = getpid ();
   credentials->native.cmcred_euid = geteuid ();
   credentials->native.cmcred_gid  = getegid ();
+#elif G_CREDENTIALS_USE_NETBSD_UNPCBID
+  credentials->native.unp_pid = getpid ();
+  credentials->native.unp_euid = geteuid ();
+  credentials->native.unp_egid = getegid ();
 #elif G_CREDENTIALS_USE_OPENBSD_SOCKPEERCRED
   credentials->native.pid = getpid ();
   credentials->native.uid = geteuid ();
@@ -212,6 +221,15 @@ g_credentials_to_string (GCredentials *c
     g_string_append_printf (ret, "uid=%" G_GINT64_FORMAT ",", (gint64) credentials->native.cmcred_euid);
   if (credentials->native.cmcred_gid != -1)
     g_string_append_printf (ret, "gid=%" G_GINT64_FORMAT ",", (gint64) credentials->native.cmcred_gid);
+#elif G_CREDENTIALS_USE_NETBSD_UNPCBID
+  g_string_append (ret, "netbsd-unpcbid:");
+  if (credentials->native.unp_pid != -1)
+    g_string_append_printf (ret, "pid=%" G_GINT64_FORMAT ",", (gint64) credentials->native.unp_pid);
+  if (credentials->native.unp_euid != -1)
+    g_string_append_printf (ret, "uid=%" G_GINT64_FORMAT ",", (gint64) credentials->native.unp_euid);
+  if (credentials->native.unp_egid != -1)
+    g_string_append_printf (ret, "gid=%" G_GINT64_FORMAT ",", (gint64) credentials->native.unp_egid);
+  ret->str[ret->len - 1] = '\0';
 #elif G_CREDENTIALS_USE_OPENBSD_SOCKPEERCRED
   g_string_append (ret, "openbsd-sockpeercred:");
   if (credentials->native.pid != -1)
@@ -278,6 +296,9 @@ g_credentials_is_same_user (GCredentials
 #elif G_CREDENTIALS_USE_FREEBSD_CMSGCRED
   if (credentials->native.cmcred_euid == other_credentials->native.cmcred_euid)
     ret = TRUE;
+#elif G_CREDENTIALS_USE_NETBSD_UNPCBID
+  if (credentials->native.unp_euid == other_credentials->native.unp_euid)
+    ret = TRUE;
 #elif G_CREDENTIALS_USE_OPENBSD_SOCKPEERCRED
   if (credentials->native.uid == other_credentials->native.uid)
     ret = TRUE;
@@ -431,6 +452,8 @@ g_credentials_get_unix_user (GCredential
   ret = credentials->native.uid;
 #elif G_CREDENTIALS_USE_FREEBSD_CMSGCRED
   ret = credentials->native.cmcred_euid;
+#elif G_CREDENTIALS_USE_NETBSD_UNPCBID
+  ret = credentials->native.unp_euid;
 #elif G_CREDENTIALS_USE_OPENBSD_SOCKPEERCRED
   ret = credentials->native.uid;
 #elif G_CREDENTIALS_USE_SOLARIS_UCRED
@@ -475,6 +498,8 @@ g_credentials_get_unix_pid (GCredentials
   ret = credentials->native.pid;
 #elif G_CREDENTIALS_USE_FREEBSD_CMSGCRED
   ret = credentials->native.cmcred_pid;
+#elif G_CREDENTIALS_USE_NETBSD_UNPCBID
+  ret = credentials->native.unp_pid;
 #elif G_CREDENTIALS_USE_OPENBSD_SOCKPEERCRED
   ret = credentials->native.pid;
 #elif G_CREDENTIALS_USE_SOLARIS_UCRED
@@ -526,6 +551,9 @@ g_credentials_set_unix_user (GCredential
 #elif G_CREDENTIALS_USE_FREEBSD_CMSGCRED
   credentials->native.cmcred_euid = uid;
   ret = TRUE;
+#elif G_CREDENTIALS_USE_NETBSD_UNPCBID
+  credentials->native.unp_euid = uid;
+  ret = TRUE;
 #elif G_CREDENTIALS_USE_OPENBSD_SOCKPEERCRED
   credentials->native.uid = uid;
   ret = TRUE;
