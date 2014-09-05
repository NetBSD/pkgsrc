$NetBSD: patch-gio_gsocket.c,v 1.1 2014/09/05 20:49:55 prlw1 Exp $

gcredentials: add NetBSD support
https://bugzilla.gnome.org/show_bug.cgi?id=728256

--- gio/gsocket.c.orig	2014-02-23 05:47:05.000000000 +0000
+++ gio/gsocket.c
@@ -4458,6 +4458,23 @@ g_socket_get_credentials (GSocket   *soc
                                   native_creds_buf);
       }
   }
+#elif G_CREDENTIALS_USE_NETBSD_UNPCBID
+  {
+    struct unpcbid cred;
+    socklen_t optlen = sizeof (cred);
+
+    if (getsockopt (socket->priv->fd,
+                    0,
+                    LOCAL_PEEREID,
+                    &cred,
+                    &optlen) == 0)
+      {
+        ret = g_credentials_new ();
+        g_credentials_set_native (ret,
+                                  G_CREDENTIALS_NATIVE_TYPE,
+                                  &cred);
+      }
+  }
 #elif G_CREDENTIALS_USE_SOLARIS_UCRED
   {
     ucred_t *ucred = NULL;
