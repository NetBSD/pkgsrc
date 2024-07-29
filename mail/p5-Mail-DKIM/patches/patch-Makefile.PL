$NetBSD: patch-Makefile.PL,v 1.2 2024/07/29 01:54:28 wen Exp $

--- Makefile.PL.orig	2024-07-29 01:36:08.663599670 +0000
+++ Makefile.PL
@@ -42,6 +42,7 @@ my %WriteMakefileArgs = (
     "lib" => 0
   },
   "VERSION" => "1.20240619",
+  "EXE_FILES" => [qw(scripts/arcsign.pl scripts/arcverify.pl scripts/dkimsign.pl scripts/dkimverify.pl)],
   "test" => {
     "TESTS" => "t/*.t"
   }
