$NetBSD: patch-helpers_docbook2man-spec.pl,v 1.1 2026/01/03 18:05:45 bsiegert Exp $

Use onsgmls from openjade.

--- helpers/docbook2man-spec.pl.orig	2026-01-02 20:15:42.180989033 +0000
+++ helpers/docbook2man-spec.pl
@@ -7,7 +7,7 @@ docbook2man-spec - convert DocBook RefEn
 The SGMLSpm package from CPAN.  This contains the sgmlspl script which
 is used to grok this file.  Use it like this:
 
-nsgmls some-docbook-document.sgml | sgmlspl docbook2man-spec.pl
+onsgmls some-docbook-document.sgml | sgmlspl docbook2man-spec.pl
 
 =head1 DESCRIPTION
 
