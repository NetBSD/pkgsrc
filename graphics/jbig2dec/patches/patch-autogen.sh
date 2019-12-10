$NetBSD: patch-autogen.sh,v 1.1 2019/12/10 10:36:00 leot Exp $

`+' is an ordinary character in obsolete ('basic') regular expression,
rewrite it to use `*'.

--- autogen.sh.orig	2019-10-02 12:52:19.000000000 +0000
+++ autogen.sh
@@ -22,7 +22,7 @@ VERSIONGREP="sed -e s/.*[^0-9\.]\([0-9][
 VERSIONMKMAJ="sed -e s/\([0-9][0-9]*\)[^0-9].*/\\1/"
 VERSIONMKMIN="sed -e s/.*[0-9][0-9]*\.//"
 
-JBIG2VERSIONGREP="sed -e s/^.*(\([0-9]\+\)).*/\\1/"
+JBIG2VERSIONGREP="sed -e s/^.*(\([0-9][0-9]*\)).*/\\1/"
 JBIG2MAJOR=$(grep 'define JBIG2_VERSION_MAJOR' jbig2.h | $JBIG2VERSIONGREP)
 JBIG2MINOR=$(grep 'define JBIG2_VERSION_MINOR' jbig2.h | $JBIG2VERSIONGREP)
 sed -e "s/^\(AC_INIT[^,]*,\)[^,]*\(,.*\)$/\1 [$JBIG2MAJOR.$JBIG2MINOR]\2/" configure.ac.in > configure.ac
