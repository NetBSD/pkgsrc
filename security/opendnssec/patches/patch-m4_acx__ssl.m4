$NetBSD: patch-m4_acx__ssl.m4,v 1.1 2020/06/08 15:07:43 he Exp $

--- m4/acx_ssl.m4.orig	2017-02-23 09:28:27.000000000 +0000
+++ m4/acx_ssl.m4
@@ -43,6 +43,7 @@ AC_DEFUN([ACX_SSL], [
                             AC_MSG_ERROR([OpenSSL found in $ssldir, but version 0.9.7 or higher is required])
                     ])
             ] )
+	    AC_CHECK_LIB(crypto, EVP_sha1)
             AC_CHECK_FUNCS([EVP_sha1 EVP_sha256])
         fi
         AC_SUBST(HAVE_SSL)
