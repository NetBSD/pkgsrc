$NetBSD: patch-install.sh,v 1.1 2020/05/18 16:17:21 nia Exp $

Fix installation paths for pkgsrc.

--- install.sh.orig	2018-07-31 00:07:25.000000000 +0000
+++ install.sh
@@ -562,7 +562,7 @@ install_components() {
 	    if echo "$_file" | grep "^etc/" > /dev/null
 	    then
 		local _f="$(echo "$_file" | sed 's/^etc\///')"
-		_file_install_path="$CFG_SYSCONFDIR/$_f"
+		_file_install_path="$CFG_DESTDIR_PREFIX/share/doc/cargo/$_f"
 	    fi
 
 	    if echo "$_file" | grep "^bin/" > /dev/null
@@ -586,7 +586,7 @@ install_components() {
 	    if echo "$_file" | grep "^share/man/" > /dev/null
 	    then
 		local _f="$(echo "$_file" | sed 's/^share\/man\///')"
-		_file_install_path="$CFG_MANDIR/$_f"
+		_file_install_path="$CFG_DESTDIR_PREFIX/$PKGMANDIR/$_f"
 	    fi
 
             # HACK: Try to support overriding --docdir.  Paths with the form
