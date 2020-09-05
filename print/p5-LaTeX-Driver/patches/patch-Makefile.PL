$NetBSD: patch-Makefile.PL,v 1.2 2020/09/05 07:14:05 wiz Exp $

Somehow doesn't some dependencies as new enough, so just comment out the check.

--- Makefile.PL.orig	2016-04-15 18:40:39.000000000 +0000
+++ Makefile.PL
@@ -28,8 +28,8 @@ test_requires 'Test::More' => '0.88';
 
 author_requires 'Test::NoTabs';
 author_requires 'Test::Pod' => '1.14';
-author_requires 'Test::Pod::Coverage' => '1.04';
-author_requires 'Test::Spelling' => '0.11';
+#author_requires 'Test::Pod::Coverage' => '1.04';
+#author_requires 'Test::Spelling' => '0.11';
 
 install_script 'latex2dvi';
 install_script 'latex2pdf';
