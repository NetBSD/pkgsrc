$NetBSD: manual-funclib.sh,v 1.1 2017/03/06 16:14:07 jperkin Exp $

Avoid pkgsrc variables which are not suitable here.

--- build-aux/funclib.sh.orig	2015-01-20 19:18:37.000000000 +0000
+++ build-aux/funclib.sh
@@ -244,6 +244,9 @@ test -z "$GREP" && {
 # uses them if a suitable command of that name is not already available
 # in the command search PATH.
 
+unset CP
+unset MV
+unset RM
 : ${CP="cp -f"}
 : ${ECHO="printf %s\n"}
 : ${EGREP="$GREP -E"}
