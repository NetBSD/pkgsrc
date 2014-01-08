$NetBSD: patch-ra.sh,v 1.1.2.2 2014/01/08 18:53:27 tron Exp $

--- ra.sh.orig	2010-12-13 03:42:49.000000000 +0000
+++ ra.sh
@@ -31,7 +31,7 @@ EDITOR=${EDITOR:-vi}
 PAGER=${PAGER:-cat}
 USER=${SUDO_USER:-$USER}
 TMPDIR="${TMPDIR:=/tmp}"
-DEFAULTS="/etc/defaults/radmind"
+DEFAULTS="_PKG_SYSCONFDIR/radmind.defaults"
 FSDIFFROOT="."
 DEFAULTWORKDIR="/"
 FLAG="_RADMIND_DIR/client/.RadmindRunning"
@@ -46,7 +46,7 @@ NETOPTS=
 PREAPPLY="_RADMIND_PREAPPLY"
 POSTAPPLY="_RADMIND_POSTAPPLY"
 
-PATH=/usr/local/bin:/usr/bin:/bin; export PATH
+PATH=_LOCALBASE/bin:/usr/bin:/bin; export PATH
 RETRY=10
 
 MKTEMP="_RADMIND_MKTEMP"
@@ -62,14 +62,6 @@ fi
 LTMP="${RASHTMP}/lapply.out"
 FTMP="${RASHTMP}/fsdiff.out"
 
-# different systems use different default dirs
-if [ ! -f "${DEFAULTS}" ]; then
-    DEFAULTS="/etc/default/radmind"
-    if [ ! -f "${DEFAULTS}" ]; then
-	DEFAULTS="/etc/radmind.defaults"
-    fi
-fi
-
 Yn() {
     $ECHO -n "$*" "[Yn] "
     read ans
