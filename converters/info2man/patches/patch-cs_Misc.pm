$NetBSD: patch-cs_Misc.pm,v 1.1 2023/04/30 14:07:04 nikita Exp $

Eliminate old-fashioned call for flush.pl

--- cs/Misc.pm.orig	2001-04-18 04:46:15.000000000 +0200
+++ cs/Misc.pm	2023-04-30 15:50:47.006259755 +0200
@@ -8,7 +8,7 @@
 
 BEGIN { use cs::DEBUG; cs::DEBUG::using(__FILE__); }
 
-require 'flush.pl';	# for ::flush()
+# require 'flush.pl';	# for ::flush()
 use cs::Math;
 
 package cs::Misc;
