$NetBSD: patch-subversion_include_svn_auth.h,v 1.1 2013/09/05 07:07:46 adam Exp $

Allow GNOME keyring functions on Darwin, or other svn packages won't build.

--- subversion/include/svn_auth.h.orig	2013-09-05 06:34:51.000000000 +0000
+++ subversion/include/svn_auth.h
@@ -966,7 +966,7 @@ svn_auth_get_keychain_ssl_client_cert_pw
   apr_pool_t *pool);
 #endif /* DARWIN || DOXYGEN */
 
-#if (!defined(DARWIN) && !defined(WIN32)) || defined(DOXYGEN)
+#if !defined(WIN32) || defined(DOXYGEN)
 /** A type of callback function for obtaining the GNOME Keyring password.
  *
  * In this callback, the client should ask the user for default keyring
