$NetBSD: patch-share_common.sh,v 1.2 2017/02/09 10:37:12 hauke Exp $

Fix absolute paths.
Normalize prefs filename.

--- share/common.sh.orig	2016-10-17 14:13:06.000000000 +0000
+++ share/common.sh
@@ -2,16 +2,12 @@
 
 UNBURDEN_BASENAME=${UNBURDEN_BASENAME:-unburden-home-dir}
 
-if [ -e /etc/default/"${UNBURDEN_BASENAME}" ]; then
-    . /etc/default/"${UNBURDEN_BASENAME}"
+if [ -e @PKG_SYSCONFDIR@/"${UNBURDEN_BASENAME}".conf ]; then
+    . @PKG_SYSCONFDIR@/"${UNBURDEN_BASENAME}".conf
 fi
 
-if [ -e /etc/"${UNBURDEN_BASENAME}" ]; then
-    . /etc/"${UNBURDEN_BASENAME}"
-fi
-
-if [ -e "${HOME}/.${UNBURDEN_BASENAME}" ]; then
-    . "${HOME}/.${UNBURDEN_BASENAME}"
+if [ -e "${HOME}/.${UNBURDEN_BASENAME}".conf ]; then
+    . "${HOME}/.${UNBURDEN_BASENAME}".conf
 fi
 
 if [ -e "${XDG_CONFIG_HOME:-$HOME/.config}/${UNBURDEN_BASENAME}/config" ]; then
