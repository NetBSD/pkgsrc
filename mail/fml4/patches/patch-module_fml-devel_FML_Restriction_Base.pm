$NetBSD: patch-module_fml-devel_FML_Restriction_Base.pm,v 1.1.2.2 2019/05/12 20:47:11 spz Exp $

* Avoid function redefinition.

--- module/fml-devel/FML/Restriction/Base.pm.orig	2003-12-06 15:41:33.000000000 +0000
+++ module/fml-devel/FML/Restriction/Base.pm
@@ -10,7 +10,6 @@ package FML::Restriction::Base;
 
 use vars qw($debug @ISA @EXPORT @EXPORT_OK);
 use strict;
-use Carp;
 
 =head1 NAME
 
