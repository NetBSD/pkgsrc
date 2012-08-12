$NetBSD: patch-genchars.sh,v 1.1 2012/08/12 11:52:26 obache Exp $

--- genchars.sh.orig	2001-08-13 18:30:48.000000000 +0900
+++ genchars.sh	2011-08-21 23:37:29.000000000 +0900
@@ -1,6 +1,6 @@
 #! /bin/sh
 
-ruby -rromkan -nle 'head = split[0]; if /^\w+$/ =~ head then puts head else roma = head.to_roma; puts roma, roma.to_kunrei end' migemo-dict |uniq> tmp.ascii.words
+ruby -rromkan -nle 'head = $_.split[0]; if /^\w+$/ =~ head then puts head else roma = head.to_roma; puts roma, roma.to_kunrei end' migemo-dict |uniq> tmp.ascii.words
 
 # Get the top 500 frequent ngrams.
 for i in 1 2 3 4 5 6 7 8; do
