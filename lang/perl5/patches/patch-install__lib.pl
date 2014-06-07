$NetBSD: patch-install__lib.pl,v 1.1 2014/06/07 11:58:39 obache Exp $

* File::Copy is used for the case link() is not usable.

--- install_lib.pl.orig	2014-06-07 09:51:07.000000000 +0000
+++ install_lib.pl
@@ -8,6 +8,7 @@ use vars qw($Is_VMS $Is_W32 $Is_OS2 $Is_
 	    %opts $packlist);
 use subs qw(unlink link chmod);
 require File::Path;
+require File::Copy;
 
 BEGIN {
     require Config;
