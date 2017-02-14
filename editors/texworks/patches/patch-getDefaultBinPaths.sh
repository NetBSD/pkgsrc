$NetBSD: patch-getDefaultBinPaths.sh,v 1.4 2017/02/14 09:19:43 markd Exp $

--- getDefaultBinPaths.sh.orig	2016-05-01 08:43:14.000000000 +0000
+++ getDefaultBinPaths.sh
@@ -74,14 +74,14 @@ case $PLATFORM in
 	*)			OS=`echo $PLATFORM | sed 's/.*-//'`
 esac
 
-appendPath "/usr/local/texlive/2017/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2016/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2015/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2014/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2013/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2012/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2011/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2010/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2017/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2016/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2015/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2014/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2013/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2012/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2011/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2010/bin/$ARCH-$OS"
 
 for TEXLIVEROOT in /usr/local/texlive/* /opt/texlive/*; do
 	# Check if this is really a folder (e.g., /opt/... might not exist)
