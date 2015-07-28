$NetBSD: patch-foo2zjs-pstops.sh,v 1.1 2015/07/28 16:42:03 rumko Exp $

Use gsed on all systems instead of just Darwin.

--- foo2zjs-pstops.sh.orig	2012-02-23 21:19:46.000000000 +0000
+++ foo2zjs-pstops.sh
@@ -48,7 +48,7 @@ debug() {
 #
 case `uname -s` in
 Darwin)	sed=gsed;;
-*)	sed=sed;;
+*)	sed=gsed;;
 esac
 
 #
