$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 08:22:45 ryoon Exp $

* Add workaround for . removal from @INC

--- Makefile.PL.orig	2012-05-13 02:34:31.000000000 +0000
+++ Makefile.PL
@@ -1,5 +1,7 @@
 #!/usr/bin/perl
 use strict;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Package 'Au:dry 1';
 
 my $DefaultVersion  = 'v5.0.0';
