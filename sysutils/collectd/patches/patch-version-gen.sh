$NetBSD: patch-version-gen.sh,v 1.1 2015/08/11 13:19:21 he Exp $

For work in pkgsrc, also strip '.git' suffix.

--- version-gen.sh.orig	2015-05-26 20:23:28.000000000 +0000
+++ version-gen.sh
@@ -8,6 +8,6 @@ if test -z "$VERSION"; then
 	VERSION="$DEFAULT_VERSION"
 fi
 
-VERSION="`echo \"$VERSION\" | sed -e 's/-/./g'`"
+VERSION="`echo \"$VERSION\" | sed -e 's/-/./g' | sed -e 's/.git//'`"
 
 printf "%s" "$VERSION"
