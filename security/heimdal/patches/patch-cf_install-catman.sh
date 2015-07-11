$NetBSD: patch-cf_install-catman.sh,v 1.2 2015/07/11 04:26:57 rodent Exp $

When getting a file basename strip any leading directories.

--- cf/install-catman.sh.orig	2012-12-09 22:06:44.000000000 +0000
+++ cf/install-catman.sh
@@ -14,7 +14,7 @@ catinstall="${INSTALL_CATPAGES-yes}"
 
 for f in "$@"; do
         echo $f
-	base=`echo "$f" | sed 's/\.[^.]*$//'`
+	base=`echo "$f" | sed 's/\.[^.]*$//;s,.*/,,'`
 	section=`echo "$f" | sed 's/^[^.]*\.//'`
 	mandir="$manbase/man$section"
 	catdir="$manbase/cat$section"
