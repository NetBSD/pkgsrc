$NetBSD: patch-Fileinfo.hh,v 1.1 2023/06/08 14:35:46 joerg Exp $

--- Fileinfo.hh.orig	2023-06-01 12:41:44.522906826 +0000
+++ Fileinfo.hh
@@ -8,6 +8,7 @@
 #define Fileinfo_hh
 
 #include <array>
+#include <cstdint>
 #include <string>
 
 // os specific headers
