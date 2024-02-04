$NetBSD: patch-Makefile.PL,v 1.1 2024/02/04 05:48:29 schmonz Exp $

Install the scripts.

--- Makefile.PL.orig	2024-01-24 04:01:35.000000000 +0000
+++ Makefile.PL
@@ -41,6 +41,7 @@ my %WriteMakefileArgs = (
     "lib" => 0
   },
   "VERSION" => "1.20240124",
+  "EXE_FILES" => [qw(scripts/arcsign.pl scripts/arcverify.pl scripts/dkimsign.pl scripts/dkimverify.pl)],
   "test" => {
     "TESTS" => "t/*.t"
   }
