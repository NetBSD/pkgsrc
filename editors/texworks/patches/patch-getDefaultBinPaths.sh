$NetBSD: patch-getDefaultBinPaths.sh,v 1.2 2012/10/28 03:33:45 markd Exp $

--- getDefaultBinPaths.sh.orig	2012-04-29 16:00:44.000000000 +0000
+++ getDefaultBinPaths.sh
@@ -74,12 +74,12 @@ case $PLATFORM in
 	*)			OS=`echo $PLATFORM | sed 's/.*-//'`
 esac
 
-appendPath "/usr/local/texlive/2012/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2011/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2010/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2009/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2008/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2007/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2012/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2011/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2010/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2009/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2008/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2007/bin/$ARCH-$OS"
 
 for TEXLIVEROOT in /usr/local/texlive/* /opt/texlive/*; do
 	# Check if this is really a folder (e.g., /opt/... might not exist)
