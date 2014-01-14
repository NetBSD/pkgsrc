$NetBSD: patch-getDefaultBinPaths.sh,v 1.3 2014/01/14 08:56:08 markd Exp $

--- getDefaultBinPaths.sh.orig	2013-04-14 13:45:23.000000000 +0000
+++ getDefaultBinPaths.sh
@@ -74,13 +74,13 @@ case $PLATFORM in
 	*)			OS=`echo $PLATFORM | sed 's/.*-//'`
 esac
 
-appendPath "/usr/local/texlive/2013/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2012/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2011/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2010/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2009/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2008/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2007/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2013/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2012/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2011/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2010/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2009/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2008/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2007/bin/$ARCH-$OS"
 
 for TEXLIVEROOT in /usr/local/texlive/* /opt/texlive/*; do
 	# Check if this is really a folder (e.g., /opt/... might not exist)
