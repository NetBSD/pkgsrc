$NetBSD: patch-getDefaultBinPaths.sh,v 1.5 2018/01/11 09:32:01 markd Exp $

--- getDefaultBinPaths.sh.orig	2017-04-29 16:23:51.000000000 +0000
+++ getDefaultBinPaths.sh
@@ -74,15 +74,15 @@ case $PLATFORM in
 	*)			OS=`echo $PLATFORM | sed 's/.*-//'`
 esac
 
-appendPath "/usr/local/texlive/2018/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2017/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2016/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2015/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2014/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2013/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2012/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2011/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2010/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2018/bin/$ARCH-$OS"
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
