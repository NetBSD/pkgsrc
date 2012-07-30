$NetBSD: patch-config_amanda_krb5-security.m4,v 1.1 2012/07/30 07:21:11 sbd Exp $

* Make passing the krb5 location to '--with-krb5-security=' work.
* Make building with Heimdal work

--- config/amanda/krb5-security.m4.orig	2012-02-21 11:36:49.000000000 +0000
+++ config/amanda/krb5-security.m4
@@ -27,7 +27,7 @@ AC_DEFUN([AMANDA_KRB5_SECURITY],
             case "$withval" in
                 n | no) KRB5_SECURITY=no ;;
                 y | ye | yes) KRB5_SECURITY=yes ;;
-                *) KRB5_SPOTS="$KRB5_SECURITY"
+                *) KRB5_SPOTS="$withval"
                    KRB5_SECURITY=yes
                    ;;
             esac
@@ -61,6 +61,8 @@ AC_DEFUN([AMANDA_KRB5_SECURITY],
                 AMANDA_ADD_LIBS([-lgssapi_krb5 -lkrb5 $K5CRYPTO $K5SUPPORT -lcom_err])
                 break
             elif test \( -f ${k5libdir}/libkrb5.a -o -f ${k5libdir}/libkrb5.so \) -a \( -f ${k5libdir}/libasn1.a -o -f ${k5libdir}/libasn1.so \) -a \( -f ${k5libdir}/libgssapi.a -o -f ${k5libdir}/libgssapi.so \); then
+                KRB5_DIR_FOUND=$dir
+                KRB5_LIBDIR_FOUND=$k5libdir
                 AMANDA_ADD_LIBS([-lgssapi -lkrb5 -lasn1])
                 AMANDA_ADD_CPPFLAGS([-DKRB5_HEIMDAL_INCLUDES])
                 break
