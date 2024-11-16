$NetBSD: patch-hints_netbsd.sh,v 1.11 2024/11/16 11:54:24 wiz Exp $

Better defaults for paths.

--- hints/netbsd.sh.orig	2024-11-16 08:28:23.750420799 +0000
+++ hints/netbsd.sh
@@ -200,10 +200,11 @@ esac
 EOCBU
 
 # Set sensible defaults for NetBSD: look for local software in
-# /usr/pkg (NetBSD Packages Collection) and in /usr/local.
+# /usr/local, plus the build prefix, which might or might not be
+# /usr/pkg.
 #
-loclibpth="/usr/pkg/lib /usr/local/lib"
-locincpth="/usr/pkg/include /usr/local/include"
+loclibpth="${prefix}/lib /usr/local/lib"
+locincpth="${prefix}/include /usr/local/include"
 case "$rpathflag" in
 '')
 	ldflags=
