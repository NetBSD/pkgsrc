$NetBSD: patch-autotests_input_highlight.sh,v 1.1 2024/05/26 13:12:39 markd Exp $

--- autotests/input/highlight.sh.orig	2017-12-02 20:10:35.000000000 +0000
+++ autotests/input/highlight.sh
@@ -159,9 +159,9 @@ make  destdir=/usr/
 
 # [[ and [ correctly need spaces to be regarded as structure,
 # otherwise they are patterns (currently treated as normal text)
-if [ "$p" == "" ] ; then
+if [ "$p" = "" ] ; then
 	ls /usr/bin/[a-z]*
-elif [[ $p == 0 ]] ; then
+elif [[ $p = 0 ]] ; then
 	ls /usr/share/$p
 fi
 
