$NetBSD: patch-tcpdump2xplot.pl,v 1.1 2011/03/28 19:36:30 gdt Exp $

# This patch contains minor changes to parsing tcpdump to adapt to
# tcpdump's output changes.  These changes should be merged upstream.
# Upstream has no bug tracker but $MAINTAINER is an upstream maintainer.
# Specifically:
#   omit tos information - we don't use it and it confuses the parser
#   bare split breaks in modern perl - assgin to @_ explicitly
#   remove "IP" as second field
#   allow multiple spaces when splitting sack.

--- tcpdump2xplot.pl.orig	2006-07-27 19:55:59.000000000 +0000
+++ tcpdump2xplot.pl
@@ -229,12 +229,16 @@ for ($lineNo = 1; <$Tcpdump>; $lineNo++)
     local(%opts);
 
     chop;
+    # strip unwanted output added by modern tcdump versions in verbose mode
+    s/\(tos.*?\)//;     # (tos 0x0, ttl ... length: \d+)
+    s/ \[(?:bad )?tcp (?:ck)?sum.*?\]//; # [tcp sum ok]/[bad tcp cksum ....]
     $opts = $_;   # save this for later 
 
-    split(/ /);
-    if ($_[1] == "IP") {
-	splice @_,1,1;
-    }
+    @_ = split(/ +/);
+    # Sometime after version 3.7.1 tcpdump started to print 'IP'
+    # as the second field in the output. Get rid of it again.
+    # also remove additional fields printed in verbose mode
+    splice @_, 1, 1 if $_[1] eq 'IP';
     $time = $_[0];
 
     # If there is if_signal.c-style signal strength info, elide it.
@@ -432,7 +436,7 @@ for ($lineNo = 1; <$Tcpdump>; $lineNo++)
 
 		# print stderr "SACKS after : $sacks \n";
 
-		@sacks = split(/ /, $sacks);
+		@sacks = split(/ +/, $sacks);
 		
 		for ($i = 0; $i <= $#sacks; $i++) {
 		    local($start);
