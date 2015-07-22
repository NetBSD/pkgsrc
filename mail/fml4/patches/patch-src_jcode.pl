$NetBSD: patch-src_jcode.pl,v 1.1.2.2 2015/07/22 20:07:53 tron Exp $

Avoid use of obsolete perl syntax.

--- src/jcode.pl.orig	2000-01-05 04:57:47.000000000 +0000
+++ src/jcode.pl
@@ -676,7 +676,7 @@ sub __z2h_jis {
 
 sub z2h_euc {
     local(*s, $n) = @_;
-    &init_z2h_euc unless defined %z2h_euc;
+    &init_z2h_euc unless %z2h_euc;
     $s =~ s/($re_euc_c|$re_euc_kana)/
 	$z2h_euc{$1} ? ($n++, $z2h_euc{$1}) : $1
     /geo;
@@ -685,7 +685,7 @@ sub z2h_euc {
 
 sub z2h_sjis {
     local(*s, $n) = @_;
-    &init_z2h_sjis unless defined %z2h_sjis;
+    &init_z2h_sjis unless %z2h_sjis;
     $s =~ s/($re_sjis_c)/$z2h_sjis{$1} ? ($n++, $z2h_sjis{$1}) : $1/geo;
     $n;
 }
