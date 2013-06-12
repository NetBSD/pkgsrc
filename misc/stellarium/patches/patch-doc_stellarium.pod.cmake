$NetBSD: patch-doc_stellarium.pod.cmake,v 1.1 2013/06/12 15:29:13 wiz Exp $

Set encoding so this builds with perl-5.18's pod2man.

--- doc/stellarium.pod.cmake.orig	2013-03-26 10:44:46.000000000 +0000
+++ doc/stellarium.pod.cmake
@@ -1,3 +1,5 @@
+=encoding iso-8859-1
+
 =head1 NAME
 
 stellarium - A real-time realistic planetarium
