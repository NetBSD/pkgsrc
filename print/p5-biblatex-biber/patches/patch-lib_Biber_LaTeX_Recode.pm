$NetBSD: patch-lib_Biber_LaTeX_Recode.pm,v 1.1 2016/03/30 05:33:00 markd Exp $

Work with perl 5.22

--- lib/Biber/LaTeX/Recode.pm.orig	2014-06-26 07:25:09.000000000 +0000
+++ lib/Biber/LaTeX/Recode.pm
@@ -5,6 +5,8 @@ use warnings;
 use base qw(Exporter);
 use Biber::Config;
 use Encode;
+use File::Slurp;
+use File::Spec;
 use IPC::Cmd qw( can_run );
 use IPC::Run3; # This works with PAR::Packer and Windows. IPC::Run doesn't
 use Unicode::Normalize;
@@ -261,7 +263,7 @@ sub latex_decode {
         $text =~ s/\\textsuperscript{\\($re)}/$map->{$1}/ge if $re;
       }
       elsif ($type eq 'dings') {
-        $text =~ s/\\ding{([2-9AF][0-9A-F])}/$map->{$1}/ge;
+        $text =~ s/\\ding\{([2-9AF][0-9A-F])\}/$map->{$1}/ge;
       }
       elsif ($type eq 'letters') {
         $text =~ s/\\($re)(?: \{\}|\s+|\b)/$map->{$1}/gxe;
