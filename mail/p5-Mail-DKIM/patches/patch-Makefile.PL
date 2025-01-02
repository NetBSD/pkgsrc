$NetBSD: patch-Makefile.PL,v 1.3 2025/01/02 08:16:35 wen Exp $

--- Makefile.PL.orig	2024-09-23 04:56:12.000000000 +0000
+++ Makefile.PL
@@ -42,6 +42,7 @@ my %WriteMakefileArgs = (
     "lib" => 0
   },
   "VERSION" => "1.20240923",
+  "EXE_FILES" => [qw(scripts/arcsign.pl scripts/arcverify.pl scripts/dkimsign.pl scripts/dkimverify.pl)],
   "test" => {
     "TESTS" => "t/*.t"
   }
