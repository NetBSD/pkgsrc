$NetBSD: patch-php_config.m4,v 1.1 2014/02/12 11:43:53 fhajny Exp $

Rename package files to avoid conflict with devel/libuuid (based
on Debian patches).

--- php/config.m4.orig	2007-05-19 19:26:56.000000000 +0000
+++ php/config.m4
@@ -34,7 +34,7 @@ if test "$PHP_UUID" != "no"; then
     PHP_NEW_EXTENSION(uuid, uuid.c, $ext_shared)
     AC_DEFINE(HAVE_UUID, 1, [Have OSSP uuid library])
     PHP_ADD_LIBPATH([..], )
-    PHP_ADD_LIBRARY([uuid],, UUID_SHARED_LIBADD)
+    PHP_ADD_LIBRARY([ossp-uuid],, UUID_SHARED_LIBADD)
     PHP_ADD_INCLUDE([..])
     PHP_SUBST(UUID_SHARED_LIBADD)
 
