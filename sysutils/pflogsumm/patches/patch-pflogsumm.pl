$NetBSD: patch-pflogsumm.pl,v 1.1 2019/12/01 04:21:56 kim Exp $

Fix IPv6 matching in the bracket case.

--- pflogsumm.pl.orig	2012-02-05 22:25:25.000000000 +0000
+++ pflogsumm.pl
@@ -1536,7 +1536,7 @@
     # split domain/ipaddr into separates
     # newer versions of Postfix have them "dom.ain[i.p.add.ress]"
     # older versions of Postfix have them "dom.ain/i.p.add.ress"
-    unless((($domain, $ipAddr) = /^([^\[]+)\[((?:\d{1,3}\.){3}\d{1,3})\]/) == 2 ||
+    unless((($domain, $ipAddr) = /^([^\[]+)\[([0-9a-f.:]+)\]/i) == 2 ||
            (($domain, $ipAddr) = /^([^\/]+)\/([0-9a-f.:]+)/i) == 2) {
 	# more exhaustive method
         ($domain, $ipAddr) = /^([^\[\(\/]+)[\[\(\/]([^\]\)]+)[\]\)]?:?\s*$/;
