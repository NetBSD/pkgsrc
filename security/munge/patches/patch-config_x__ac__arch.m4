$NetBSD: patch-config_x__ac__arch.m4,v 1.1.1.1 2012/02/19 03:51:17 asau Exp $

--- config/x_ac_arch.m4.orig	2006-10-31 01:17:13.000000000 +0000
+++ config/x_ac_arch.m4
@@ -57,7 +57,7 @@ AC_DEFUN([X_AC_ARCH], [
     fi
   fi
 
-  if test "$x_ac_arch" == "32"; then
+  if test "$x_ac_arch" = "32"; then
     if expr "$host_os" : "aix" >/dev/null 2>&1; then
       test -z "$OBJECT_MODE" && AC_MSG_ERROR(
         [The OBJECT_MODE variable must be exported to the shell.])
@@ -67,7 +67,7 @@ AC_DEFUN([X_AC_ARCH], [
       test -d /lib -o -d /usr/lib \
         && LDFLAGS="-L/lib -L/usr/lib $LDFLAGS"
     fi
-  elif test "$x_ac_arch" == "64"; then
+  elif test "$x_ac_arch" = "64"; then
     if expr "$host_os" : "aix" >/dev/null 2>&1; then
       test -z "$OBJECT_MODE" && AC_MSG_ERROR(
         [The OBJECT_MODE variable must be exported to the shell.])
