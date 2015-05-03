$NetBSD: patch-Makefile.PL,v 1.1 2015/05/03 20:25:50 wiz Exp $

Somehow doesn't accept 0.20 as new enough, so just comment out the check.

--- Makefile.PL.orig	2014-04-08 09:13:02.000000000 +0000
+++ Makefile.PL
@@ -28,7 +28,7 @@ test_requires 'Test::More' => '0.88';
 author_requires 'Test::NoTabs';
 author_requires 'Test::Pod' => '1.14';
 author_requires 'Test::Pod::Coverage' => '1.04';
-author_requires 'Test::Spelling' => '0.11';
+#author_requires 'Test::Spelling' => '0.11';
 
 install_script 'latex2dvi';
 install_script 'latex2pdf';
