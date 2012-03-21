$NetBSD: patch-getDefaultBinPaths.sh,v 1.1.1.1 2012/03/21 22:44:20 markd Exp $

--- getDefaultBinPaths.sh.orig	2011-06-29 17:03:14.000000000 +0000
+++ getDefaultBinPaths.sh
@@ -68,11 +68,11 @@ case $PLATFORM in
 	*)			OS=`echo $PLATFORM | sed 's/.*-//'`
 esac
 
-appendPath "/usr/local/texlive/2011/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2010/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2009/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2008/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2007/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2011/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2010/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2009/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2008/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2007/bin/$ARCH-$OS"
 
 for TEXLIVEROOT in /usr/local/texlive/* /opt/texlive/*; do
 	# Check if this is really a folder (e.g., /opt/... might not exist)
