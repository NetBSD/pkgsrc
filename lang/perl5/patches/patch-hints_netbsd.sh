$NetBSD: patch-hints_netbsd.sh,v 1.3 2013/01/03 10:11:34 dholland Exp $

--- hints/netbsd.sh~	2012-10-11 18:20:45.000000000 +0000
+++ hints/netbsd.sh
@@ -186,10 +186,12 @@ esac
 EOCBU
 
 # Set sensible defaults for NetBSD: look for local software in
-# /usr/pkg (NetBSD Packages Collection) and in /usr/local.
+# /usr/local, plus the build prefix, which might or might not be
+# /usr/pkg.
 #
-loclibpth="/usr/pkg/lib /usr/local/lib"
-locincpth="/usr/pkg/include /usr/local/include"
+loclibpth="/usr/local/lib ${prefix}/lib"
+locincpth="/usr/local/include ${prefix}/include"
+
 case "$rpathflag" in
 '')
 	ldflags=
