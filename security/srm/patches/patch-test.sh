$NetBSD: patch-test.sh,v 1.1 2016/10/27 19:49:44 kamil Exp $

Add NetBSD support

--- test.sh.orig	2015-02-26 16:12:02.000000000 +0000
+++ test.sh
@@ -187,7 +187,7 @@ OS=$(uname -s)
 if [ "$OS" = Linux ] ; then
     setfattr -n user.a1 -v "The value of extended attribute number 1" $FN
     setfattr -n user.num2 -v "A second attribute." $FN
-elif [ "$OS" = FreeBSD ] ; then
+elif [ "x$OS" = xFreeBSD -o "x$OS" = xNetBSD ] ; then
     setextattr user a1 "The value of extended attribute number 1" $FN
     setextattr user num2 "A second attribute." $FN
 elif [ "$OS" = Darwin ] ; then
