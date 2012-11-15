$NetBSD: patch-cf_install-catman.sh,v 1.1 2012/11/15 03:32:01 sbd Exp $

When getting a file basename strip any leading directories.

--- cf/install-catman.sh.orig	2012-01-10 21:53:51.000000000 +0000
+++ cf/install-catman.sh
@@ -14,7 +14,7 @@ catinstall="${INSTALL_CATPAGES-yes}"
 
 for f in "$@"; do
         echo $f
-	base=`echo "$f" | sed 's/\.[^.]*$//'`
+	base=`echo "$f" | sed 's/\.[^.]*$//;s,.*/,,'`
 	section=`echo "$f" | sed 's/^[^.]*\.//'`
 	mandir="$manbase/man$section"
 	catdir="$manbase/cat$section"
