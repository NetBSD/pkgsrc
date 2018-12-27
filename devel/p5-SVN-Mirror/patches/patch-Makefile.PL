$NetBSD: patch-Makefile.PL,v 1.1 2018/12/27 15:08:17 joerg Exp $

Check double digit Subversion numbers.

--- Makefile.PL.orig	2018-12-25 23:16:18.984396057 +0000
+++ Makefile.PL
@@ -32,6 +32,3 @@ include('ExtUtils::AutoInstall');
 auto_install();
 #sign(1);
 WriteAll( sign => 1);
-
-die "SVN::Core $required_svn must be manually installed"
-    unless eval {require SVN::Core} && $SVN::Core::VERSION >= $required_svn;
