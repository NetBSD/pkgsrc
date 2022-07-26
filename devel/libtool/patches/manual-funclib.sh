$NetBSD: manual-funclib.sh,v 1.2 2022/07/26 16:15:26 wiz Exp $

Avoid pkgsrc variables which are not suitable here.

--- build-aux/funclib.sh.orig	2022-03-17 02:44:32.000000000 +0000
+++ build-aux/funclib.sh
@@ -258,6 +258,9 @@ test -z "$GREP" && {
 # uses them if a suitable command of that name is not already available
 # in the command search PATH.
 
+unset CP
+unset MV
+unset RM
 : ${CP="cp -f"}
 : ${ECHO="printf %s\n"}
 : ${EGREP="$GREP -E"}
