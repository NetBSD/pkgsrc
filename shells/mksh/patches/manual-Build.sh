$NetBSD: manual-Build.sh,v 1.1 2020/07/06 10:11:34 jperkin Exp $

Avoid "test -e", unsupported on legacy Solaris /bin/sh.

--- Build.sh.orig	2020-06-24 10:37:23.000000000 +0000
+++ Build.sh
@@ -2734,11 +2734,11 @@ if test $legacy = 0; then
 fi
 $e
 $e Installing the manual:
-if test -e FAQ.htm; then
+if test -f FAQ.htm; then
 	$e "# $i -c -o root -g bin -m 444 FAQ.htm /usr/share/doc/mksh/"
 fi
 if test -f mksh.cat1; then
-	if test -e FAQ.htm; then
+	if test -f FAQ.htm; then
 		$e plus either
 	fi
 	$e "# $i -c -o root -g bin -m 444 lksh.cat1" \
@@ -2751,7 +2751,7 @@ $e "# $i -c -o root -g bin -m 444 lksh.1
 $e
 $e Run the regression test suite: ./test.sh
 $e Please also read the sample file dot.mkshrc and the fine manual.
-test -e FAQ.htm || \
+test -f FAQ.htm || \
     $e Run FAQ2HTML.sh and place FAQ.htm into a suitable location as well.
 exit 0
 
