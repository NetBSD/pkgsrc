$NetBSD: patch-ra.sh,v 1.3 2026/10/31 20:45:42 hauke Exp $

Insert pkgsrc-style defaults file

echo(1) is a shell built-in these days

--- ra.sh.orig	2026-10-23 00:02:17.000000000 +0000
+++ ra.sh
@@ -31,13 +31,13 @@ EDITOR=${EDITOR:-vi}
 PAGER=${PAGER:-cat}
 USER=${SUDO_USER:-$USER}
 TMPDIR="${TMPDIR:=/tmp}"
-DEFAULTS="/etc/defaults/radmind"
+DEFAULTS="_PKG_SYSCONFDIR/radmind.defaults"
 FSDIFFROOT="."
 DEFAULTWORKDIR="/"
 FLAG="_RADMIND_DIR/client/.RadmindRunning"
 CHECKEDOUT="_RADMIND_DIR/client/.CheckedOut"
 MAILDOMAIN="_RADMIND_MAIL_DOMAIN"
-ECHO="_RADMIND_ECHO_PATH"
+ECHO="echo"
 VERSION=_RADMIND_VERSION
 
 # variable containing all network-related flags (-w, -h, -p, etc.) 
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
