$NetBSD: patch-src_Helpers.h,v 1.2 2014/01/04 15:11:43 wiz Exp $

Add missing headers for streamsize type.
http://sourceforge.net/p/mp3diags/code/279/

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
