$NetBSD: patch-src_cmd_INIT_package.sh,v 1.1 2023/09/18 14:11:41 vins Exp $

install target fixes.

--- src/cmd/INIT/package.sh.orig	2023-09-15 02:28:23.000000000 +0000
+++ src/cmd/INIT/package.sh
@@ -2548,8 +2548,8 @@ do_install() # dir [ command ... ]
 	done
 	# set install directories
 	bindir=$dd/bin
-	man1dir=${dd:-/usr}/share/man/man1
-	fundir=${dd:-/usr}/share/fun
+	man1dir=${dd:-/usr}/man/man1
+	fundir=${dd:-/usr}/libexec/ksh93
 	# and off we go
 	trace mkdir -p "$bindir" "$man1dir" || exit
 	for f
@@ -2557,9 +2557,10 @@ do_install() # dir [ command ... ]
 		trace cp "bin/$f" "$bindir/" || exit
 		# install manual and autoloadable functions
 		case $f in
-		ksh)	trace cp "$PACKAGEROOT/src/cmd/ksh93/sh.1" "$man1dir/ksh.1" || exit
+		ksh)	trace cp "$PACKAGEROOT/src/cmd/ksh93/sh.1" "$man1dir/ksh93.1" || exit
 			trace mkdir -p "$fundir" || exit
 			(set +o noglob; trace cp "$PACKAGEROOT"/src/cmd/ksh93/fun/* "$fundir/") || exit
+			trace mv "$bindir/ksh" "$bindir/ksh93" || exit
 			;;
 		*)	# AT&T --man, etc. is a glorified error message: writes to stderr and exits with status 2 :-/
 			# So we cannot reliably check for success; must check the result, too.
