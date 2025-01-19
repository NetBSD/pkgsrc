$NetBSD: patch-genchars.sh,v 1.2 2025/01/19 11:24:44 taca Exp $

* Set default external encoding to EUC-JP.
* Explictly specify $_.

--- genchars.sh.orig	2001-08-13 09:30:48.000000000 +0000
+++ genchars.sh
@@ -1,6 +1,6 @@
 #! /bin/sh
 
-ruby -rromkan -nle 'head = split[0]; if /^\w+$/ =~ head then puts head else roma = head.to_roma; puts roma, roma.to_kunrei end' migemo-dict |uniq> tmp.ascii.words
+ruby -rromkan -nle 'Encoding.default_external = Encoding::EUC_JP; head = $_.split[0]; if /^\w+$/ =~ head then puts head else roma = head.to_roma; puts roma, roma.to_kunrei end' migemo-dict |uniq> tmp.ascii.words
 
 # Get the top 500 frequent ngrams.
 for i in 1 2 3 4 5 6 7 8; do
