$NetBSD: patch-server_libvncserver_auth.c,v 1.1 2016/09/22 11:31:37 richard Exp $

Do not use deprecated GnuTLS functions
http://bugzilla.gnome.org/show_bug.cgi?id=648606

--- server/libvncserver/auth.c.orig	2011-05-02 16:07:11.000000000 +0000
+++ server/libvncserver/auth.c
@@ -64,13 +64,16 @@ rfbAuthCleanupScreen(rfbScreenInfoPtr rf
 static rfbBool
 rfbAuthTLSHandshake(rfbClientPtr cl)
 {
-    static const int kx_priority[] = { GNUTLS_KX_ANON_DH, 0 };
+    /* TODO: Perform non-anonymous key exchange to prevent man-in-the-middle
+     * attacks. */
+    static const char kx_priority[] = "NORMAL:+ANON-DH";
+
     int              err;
     
     gnutls_init(&cl->tlsSession, GNUTLS_SERVER);
 
     gnutls_set_default_priority(cl->tlsSession);
-    gnutls_kx_set_priority(cl->tlsSession, kx_priority);
+    gnutls_priority_set_direct(cl->tlsSession, kx_priority, NULL);
 
     gnutls_credentials_set(cl->tlsSession,
 			   GNUTLS_CRD_ANON,
