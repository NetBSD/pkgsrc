$NetBSD: patch-install.sh,v 1.2 2016/09/08 14:34:02 jperkin Exp $

Change manpages installation directory.

--- install.sh.orig	2014-08-13 14:59:22.000000000 +0000
+++ install.sh
@@ -28,10 +28,10 @@ if [ -z "$1" ]; then
 fi
 
 BATS_ROOT="$(abs_dirname "$0")"
-mkdir -p "$PREFIX"/{bin,libexec,share/man/man{1,7}}
+mkdir -p "$PREFIX"/{bin,libexec,$PKGMANDIR/man{1,7}}
 cp -R "$BATS_ROOT"/bin/* "$PREFIX"/bin
 cp -R "$BATS_ROOT"/libexec/* "$PREFIX"/libexec
-cp "$BATS_ROOT"/man/bats.1 "$PREFIX"/share/man/man1
-cp "$BATS_ROOT"/man/bats.7 "$PREFIX"/share/man/man7
+cp "$BATS_ROOT"/man/bats.1 "$PREFIX"/$PKGMANDIR/man1
+cp "$BATS_ROOT"/man/bats.7 "$PREFIX"/$PKGMANDIR/man7
 
 echo "Installed Bats to $PREFIX/bin/bats"
