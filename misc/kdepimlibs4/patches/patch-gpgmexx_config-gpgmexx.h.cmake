$NetBSD: patch-gpgmexx_config-gpgmexx.h.cmake,v 1.1 2011/03/05 11:57:09 adam Exp $

Fix building with GPGME 1.3.0.

--- gpgme++/config-gpgme++.h.cmake.orig	2011-03-05 11:22:26.000000000 +0000
+++ gpgme++/config-gpgme++.h.cmake
@@ -67,9 +67,6 @@
 /* Define to 1 if your gpg-error has GPG_ERR_ALREADY_SIGNED */
 #cmakedefine HAVE_GPG_ERR_ALREADY_SIGNED 1
 
-#ifndef HAVE_GPG_ERR_NO_PASSPHRASE
-# define GPG_ERR_NO_PASSPHRASE GPG_ERR_INV_PASSPHRASE
-#endif
 
 #ifndef HAVE_GPG_ERR_ALREADY_SIGNED
 # define GPG_ERR_ALREADY_SIGNED GPG_ERR_USER_1
