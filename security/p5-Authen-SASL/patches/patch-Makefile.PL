$NetBSD: patch-Makefile.PL,v 1.1 2017/06/05 23:19:54 ryoon Exp $

* Add workaround for removing . from @INC

--- Makefile.PL.orig	2010-03-11 15:10:46.000000000 +0000
+++ Makefile.PL
@@ -3,6 +3,8 @@
 use strict;
 use warnings;
 use 5.005;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 name		'Authen-SASL';
