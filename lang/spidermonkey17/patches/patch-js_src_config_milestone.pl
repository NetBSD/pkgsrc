$NetBSD: patch-js_src_config_milestone.pl,v 1.1 2016/05/20 18:45:22 youri Exp $

Use of defined() for aggregates (array or hashes) is deprecated.

--- js/src/config/milestone.pl.orig	2013-02-11 22:33:22.000000000 +0000
+++ js/src/config/milestone.pl
@@ -55,7 +55,7 @@ $MILESTONE_FILE  = "$TOPSRCDIR/config/mi
 #
 my $milestone = Moz::Milestone::getOfficialMilestone($MILESTONE_FILE);
 
-if (defined(@TEMPLATE_FILE)) {
+if (@TEMPLATE_FILE) {
   my $TFILE;
 
   foreach $TFILE (@TEMPLATE_FILE) {
