$NetBSD: patch-lib_mhamain.pl,v 1.1 2011/10/30 22:03:42 spz Exp $

--- lib/mhamain.pl.orig	2011-01-09 16:18:35.000000000 +0000
+++ lib/mhamain.pl
@@ -1561,7 +1561,7 @@ sub signal_catch {
 ##	Create Index2MsgId if not defined
 ##
 sub defineIndex2MsgId {
-    if (!defined(%Index2MsgId)) {
+    if (!%Index2MsgId) {
 	foreach (keys %MsgId) {
 	    $Index2MsgId{$MsgId{$_}} = $_;
 	}
