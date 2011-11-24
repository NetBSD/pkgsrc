$NetBSD: patch-gsmlib_gsm__sorted__phonebook.cc,v 1.1 2011/11/24 14:17:06 joerg Exp $

--- gsmlib/gsm_sorted_phonebook.cc.orig	2011-11-23 15:42:03.000000000 +0000
+++ gsmlib/gsm_sorted_phonebook.cc
@@ -20,6 +20,7 @@
 #include <iostream>
 #include <fstream>
 #include <limits.h>
+#include <string.h>
 
 const int MAX_LINE_SIZE = 1000;
 
