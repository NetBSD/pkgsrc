$NetBSD: patch-lib_utils.bash,v 1.1 2022/12/27 16:11:01 schmonz Exp $

Use pkgsrc paths.

--- lib/utils.bash.orig	2022-12-14 20:53:20.000000000 +0000
+++ lib/utils.bash
@@ -5,7 +5,7 @@ GREP_OPTIONS="--color=never"
 # shellcheck disable=SC2034
 GREP_COLORS=
 
-ASDF_DIR=${ASDF_DIR:-''}
+ASDF_DIR=${ASDF_DIR:-'@PREFIX@/share/asdf'}
 ASDF_DATA_DIR=${ASDF_DATA_DIR:-''}
 
 asdf_version() {
