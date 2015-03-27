$NetBSD: patch-perl_Amanda_Report_human.pm,v 1.1 2015/03/27 23:45:29 gdt Exp $

On NetBSD 5 amd64, perl coredumps because of this call (or some
component of it), leading to not getting a report.  For now, comment
it out to get most of the report.  This has not yet been reported
upstream.

--- perl/Amanda/Report/human.pm.orig	2012-02-21 11:36:47.000000000 +0000
+++ perl/Amanda/Report/human.pm
@@ -319,7 +319,10 @@ sub print_human_amreport
     $self->calculate_stats();
 
     ## print the basic info header
-    $self->print_header();
+    # The next line crashes perl 5.20 on NetBSD 5 amd64.  Hence it is
+    # commented out as reports without the header are better than no
+    # reports.
+    #$self->print_header();
 
     ## print out statements about past and predicted tape usage
     $self->output_tapeinfo();
