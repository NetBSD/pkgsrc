$NetBSD: patch-getDefaultBinPaths.sh,v 1.6 2020/03/01 12:38:04 markd Exp $

--- getDefaultBinPaths.sh.orig	2019-03-16 17:06:14.000000000 +0000
+++ getDefaultBinPaths.sh
@@ -74,18 +74,18 @@ case $PLATFORM in
 	*)			OS=$(echo $PLATFORM | sed 's/.*-//')
 esac
 
-appendPath "/usr/local/texlive/2021/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2020/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2019/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2018/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2017/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2016/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2015/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2014/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2013/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2012/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2011/bin/$ARCH-$OS"
-appendPath "/usr/local/texlive/2010/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2021/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2020/bin/$ARCH-$OS"
+#appendPath "/usr/local/texlive/2019/bin/$ARCH-$OS"
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
