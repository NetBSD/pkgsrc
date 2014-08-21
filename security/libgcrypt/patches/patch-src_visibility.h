$NetBSD: patch-src_visibility.h,v 1.2 2014/08/21 19:55:26 wiz Exp $

GCC on SCO OpenServer 5.0.7/3.2 does not support visibility.

https://bugs.g10code.com/gnupg/issue1704

--- src/visibility.h.orig	2014-01-29 09:48:38.000000000 +0000
+++ src/visibility.h
@@ -26,7 +26,9 @@
 
 /* Include the main header here so that public symbols are mapped to
    the internal underscored ones.  */
-#ifdef _GCRY_INCLUDED_BY_VISIBILITY_C
+/* All available GCC for SCO OpenServer 5.0.7/3.2 does not support
+   visibility. */
+#if defined(_GCRY_INCLUDED_BY_VISIBILITY_C) || defined(_SCO_DS)
   /* We need to redeclare the deprecated functions without the
      deprecated attribute.  */
 # define GCRYPT_NO_DEPRECATED
@@ -48,7 +50,7 @@ gcry_err_code_t gcry_md_get (gcry_md_hd_
    NOTE: When adding new functions, please make sure to add them to
          libgcrypt.vers and libgcrypt.def as well.  */
 
-#ifdef _GCRY_INCLUDED_BY_VISIBILITY_C
+#if defined(_GCRY_INCLUDED_BY_VISIBILITY_C) || defined(_SCO_DS)
 
 /* A macro to flag a function as visible.  */
 #ifdef GCRY_USE_VISIBILITY
