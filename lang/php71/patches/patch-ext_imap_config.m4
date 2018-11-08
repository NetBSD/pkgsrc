$NetBSD: patch-ext_imap_config.m4,v 1.2 2018/11/08 13:59:11 taca Exp $

--- ext/imap/config.m4.orig	2018-11-07 15:35:32.000000000 +0000
+++ ext/imap/config.m4
@@ -48,6 +48,14 @@ AC_DEFUN([PHP_IMAP_TEST_BUILD], [
   ])
 ])
 
+dsl Must be before --with-kerberos, affects the check
+PHP_ARG_WITH(imap-linkage,use IMAP c-client linkage,
+[  --with-imap-linkage     Use IMAP c-client linkage to determine supported items.])
+
+if test "$PHP_IMAP_LINKAGE" != "no"; then  
+	AC_DEFINE(HAVE_IMAP_LINKAGE, 1, [ ])
+fi
+
 AC_DEFUN([PHP_IMAP_KRB_CHK], [
   if test "$PHP_KERBEROS" != "no"; then
     PHP_SETUP_KERBEROS(IMAP_SHARED_LIBADD,
@@ -59,7 +67,7 @@ AC_DEFUN([PHP_IMAP_KRB_CHK], [
       Check the path given to --with-kerberos (if no path is given, searches in /usr/kerberos, /usr/local and /usr )
       ])
     ])
-  else
+  elif test "$PHP_IMAP_LINKAGE" != "yes"; then
     AC_EGREP_HEADER(auth_gss, $IMAP_INC_DIR/linkage.h, [
       AC_MSG_ERROR([This c-client library is built with Kerberos support.
 
