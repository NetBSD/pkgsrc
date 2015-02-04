$NetBSD: patch-qb_config.libs.sh,v 1.1 2015/02/04 22:56:43 jmcneill Exp $

--- qb/config.libs.sh.orig	2015-02-03 06:43:44.000000000 +0000
+++ qb/config.libs.sh
@@ -99,7 +99,7 @@ if [ "$HAVE_EGL" != "no" ]; then
    # some systems have EGL libs, but no pkgconfig
    if [ "$HAVE_EGL" = "no" ]; then
       HAVE_EGL=auto && check_lib EGL "-lEGL $EXTRA_GL_LIBS"
-      [ "$HAVE_EGL" = "yes" ] && EGL_LIBS=-lEGL
+      [ "$HAVE_EGL" = "yes" ] && EGL_LIBS="-lEGL $EXTRA_GL_LIBS"
    else
       EGL_LIBS="$EGL_LIBS $EXTRA_GL_LIBS"
    fi
@@ -278,7 +278,7 @@ if [ "$HAVE_EGL" = "yes" ]; then
          add_define_make GLES_CFLAGS "$GLES_CFLAGS"
       else
          HAVE_GLES=auto check_pkgconf GLES glesv2
-         [ "$HAVE_GLES" = "no" ] && HAVE_GLES=auto check_lib GLES "-lGLESv2 $EXTRA_GL_LIBS" && add_define_make GLES_LIBS "-lGLESv2 $EXTRA_GL_LIBS"
+         [ "$HAVE_GLES" = "no" -o "$HAVE_GLES" = "auto" ] && HAVE_GLES=auto check_lib GLES "-lGLESv2 $EXTRA_GL_LIBS" && add_define_make GLES_LIBS "-lGLESv2 $EXTRA_GL_LIBS" && HAVE_GLES=yes
       fi
    fi
    if [ "$HAVE_VG" != "no" ]; then
