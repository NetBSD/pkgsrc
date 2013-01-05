$NetBSD: patch-docx2txt.pl,v 1.1 2013/01/05 20:36:58 is Exp $

--- docx2txt.pl.orig	2012-01-14 12:09:40.000000000 +0000
+++ docx2txt.pl
@@ -129,7 +129,7 @@ if ($ENV{OS} =~ /^Windows/ && !(exists $
     $userConfigDir = $ENV{HOME};
     $systemConfigDir = "/etc";
 
-    $config_tempDir = "/tmp";
+    $config_tempDir = $ENV{TMPDIR} || "/tmp";
 }
 
 
