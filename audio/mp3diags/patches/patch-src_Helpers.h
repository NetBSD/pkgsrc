$NetBSD: patch-src_Helpers.h,v 1.1 2014/01/02 15:52:56 wiz Exp $

Add missing headers for streamsize type.

--- src/Helpers.h.orig	2010-03-19 17:35:22.000000000 +0000
+++ src/Helpers.h
@@ -24,7 +24,9 @@
 #define HelpersH
 
 
+#include  <ios>
 #include  <iosfwd>
+#include  <iostream>
 #include  <string>
 #include  <stdexcept>
 #include  <cstdlib> // for exit()
