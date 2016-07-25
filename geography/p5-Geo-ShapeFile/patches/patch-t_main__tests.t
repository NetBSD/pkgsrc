$NetBSD: patch-t_main__tests.t,v 1.1 2016/07/25 09:18:55 wen Exp $
Add patch to be able to run tests without the need to install rlib,
which is not in ports and which can easily be replaced by the FindBin
The patch come from FreeBSD ports.
--- t/main_tests.t.orig	2016-07-25 08:39:51.000000000 +0000
+++ t/main_tests.t
@@ -3,7 +3,9 @@
 use Test::More;
 use strict;
 use warnings;
-use rlib '../lib', './lib';
+use FindBin;
+use lib "$FindBin::Bin/lib";
+use lib "$FindBin::Bin/../lib";
 
 use Geo::ShapeFile;
 use Geo::ShapeFile::Shape;
