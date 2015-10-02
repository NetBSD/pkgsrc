$NetBSD: patch-lib_mhamain.pl,v 1.3.2.2 2015/10/02 19:49:13 bsiegert Exp $

perl 5.22 compatipility

--- lib/mhamain.pl.orig	2015-09-26 12:30:58.000000000 +0200
+++ lib/mhamain.pl	2015-09-26 12:31:37.000000000 +0200
@@ -1562,7 +1562,7 @@
 ##
 sub defineIndex2MsgId {
     no warnings qw(deprecated);
-    if (!defined(%Index2MsgId)) {
+    if (!%Index2MsgId) {
 	foreach (keys %MsgId) {
 	    $Index2MsgId{$MsgId{$_}} = $_;
 	}
