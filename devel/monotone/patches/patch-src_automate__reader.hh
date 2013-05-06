$NetBSD: patch-src_automate__reader.hh,v 1.1 2013/05/06 14:42:54 joerg Exp $

--- src/automate_reader.hh.orig	2013-05-06 13:23:37.000000000 +0000
+++ src/automate_reader.hh
@@ -12,6 +12,7 @@
 #ifndef __AUTOMATE_READER_HH__
 #define __AUTOMATE_READER_HH__
 
+#include <ios>
 #include <vector>
 
 class automate_reader
