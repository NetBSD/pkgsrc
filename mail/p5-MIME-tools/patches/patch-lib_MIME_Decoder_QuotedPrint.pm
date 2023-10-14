$NetBSD: patch-lib_MIME_Decoder_QuotedPrint.pm,v 1.1 2023/10/14 01:13:32 markd Exp $

Perl 5.38 bundles MIME::QuotedPrint at version 3.16_01 which is not
numeric, causing spurious warnings on usage.
patch from Niko Tyni <ntyni@debian.org>
+https://bugs.debian.org/1040377

--- lib/MIME/Decoder/QuotedPrint.pm.orig	2022-07-06 14:04:46.000000000 +0000
+++ lib/MIME/Decoder/QuotedPrint.pm
@@ -1,6 +1,7 @@
 package MIME::Decoder::QuotedPrint;
 use strict;
 use warnings;
+use version;
 
 
 =head1 NAME
@@ -73,7 +74,7 @@ $VERSION = "5.510";
 # The following code is horrible.  I know.  Beat me up. --dfs
 BEGIN {
     if (!defined(&encode_qp_threearg)) {
-        if ($::MIME::QuotedPrint::VERSION >= 3.03) {
+        if (version->parse($::MIME::QuotedPrint::VERSION) >= version->parse(3.03)) {
             eval 'sub encode_qp_threearg ( $$$ ) { encode_qp(shift, shift, shift); }';
         } else {
             eval 'sub encode_qp_threearg ( $$$ ) { encode_qp(shift); }';
