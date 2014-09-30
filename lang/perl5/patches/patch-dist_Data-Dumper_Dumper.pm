$NetBSD: patch-dist_Data-Dumper_Dumper.pm,v 1.1.2.2 2014/09/30 17:03:04 tron Exp $

patch for CVE-2014-4330, remove for 5.20.1
taken from http://perl5.git.perl.org/perl.git/commitdiff/19be3be6968e2337bcdfe480693fff795ecd1304

--- dist/Data-Dumper/Dumper.pm.orig	2014-05-26 13:34:19.000000000 +0000
+++ dist/Data-Dumper/Dumper.pm
@@ -56,6 +56,7 @@ $Useperl    = 0         unless defined $
 $Sortkeys   = 0         unless defined $Sortkeys;
 $Deparse    = 0         unless defined $Deparse;
 $Sparseseen = 0         unless defined $Sparseseen;
+$Maxrecurse = 1000      unless defined $Maxrecurse;
 
 #
 # expects an arrayref of values to be dumped.
@@ -92,6 +93,7 @@ sub new {
         'bless'    => $Bless,    # keyword to use for "bless"
 #        expdepth   => $Expdepth,   # cutoff depth for explicit dumping
         maxdepth   => $Maxdepth,   # depth beyond which we give up
+	maxrecurse => $Maxrecurse, # depth beyond which we abort
         useperl    => $Useperl,    # use the pure Perl implementation
         sortkeys   => $Sortkeys,   # flag or filter for sorting hash keys
         deparse    => $Deparse,    # use B::Deparse for coderefs
@@ -350,6 +352,12 @@ sub _dump {
       return qq['$val'];
     }
 
+    # avoid recursing infinitely [perl #122111]
+    if ($s->{maxrecurse} > 0
+        and $s->{level} >= $s->{maxrecurse}) {
+        die "Recursion limit of $s->{maxrecurse} exceeded";
+    }
+
     # we have a blessed ref
     my ($blesspad);
     if ($realpack and !$no_bless) {
@@ -680,6 +688,11 @@ sub Maxdepth {
   defined($v) ? (($s->{'maxdepth'} = $v), return $s) : $s->{'maxdepth'};
 }
 
+sub Maxrecurse {
+  my($s, $v) = @_;
+  defined($v) ? (($s->{'maxrecurse'} = $v), return $s) : $s->{'maxrecurse'};
+}
+
 sub Useperl {
   my($s, $v) = @_;
   defined($v) ? (($s->{'useperl'} = $v), return $s) : $s->{'useperl'};
@@ -1105,6 +1118,16 @@ no maximum depth.
 
 =item *
 
+$Data::Dumper::Maxrecurse  I<or>  $I<OBJ>->Maxrecurse(I<[NEWVAL]>)
+
+Can be set to a positive integer that specifies the depth beyond which
+recursion into a structure will throw an exception.  This is intended
+as a security measure to prevent perl running out of stack space when
+dumping an excessively deep structure.  Can be set to 0 to remove the
+limit.  Default is 1000.
+
+=item *
+
 $Data::Dumper::Useperl  I<or>  $I<OBJ>->Useperl(I<[NEWVAL]>)
 
 Can be set to a boolean value which controls whether the pure Perl
