$NetBSD: patch-gnatlib_aclocal.m4,v 1.1 2013/07/09 10:16:02 marino Exp $

Remove BASHisms and support all BSDs

--- gnatlib/aclocal.m4.orig	2012-09-13 12:50:01.000000000 +0000
+++ gnatlib/aclocal.m4
@@ -564,7 +564,7 @@ AC_HELP_STRING(
                ;;
            esac
 
-           if test x$PYTHON_WIN32 == xyes; then
+           if test x$PYTHON_WIN32 = xyes; then
              PYTHON_VERSION=$PYTHON_MAJOR_VERSION$PYTHON_MINOR_VERSION
              PYTHON_DIR=${PYTHON_BASE}/libs
            else
@@ -643,12 +643,12 @@ AC_HELP_STRING(
             ia64-*hp-hpux11* )
                PYTHON_LIBS="-ldld -ldl -lm -Wl,-E ${PYTHON_LIBS}"
                ;;
-            *-freebsd* )
+            *-dragonfly* | *-freebsd* | *-netbsd* | *-openbsd* )
                PYTHON_LIBS="-lm -lutil ${PYTHON_LIBS}"
                ;;
          esac
 
-         if test x$PYTHON_WIN32 == xyes; then
+         if test x$PYTHON_WIN32 = xyes; then
             PYTHON_CFLAGS="-I${PYTHON_BASE}/include"
          else
             PYTHON_CFLAGS="-I${PYTHON_BASE}/include/python${PYTHON_VERSION}"
@@ -757,7 +757,7 @@ AC_DEFUN(AM_PATH_PYGOBJECT,
            module=""
        done
 
-       if test "$module" == "" ; then
+       if test "$module" = "" ; then
           AC_MSG_RESULT(no)
           WITH_PYGOBJECT=no
        else
