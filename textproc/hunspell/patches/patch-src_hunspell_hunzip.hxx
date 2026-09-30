$NetBSD: patch-src_hunspell_hunzip.hxx,v 1.1 2026/09/30 09:10:08 adam Exp $

--- src/hunspell/hunzip.hxx.orig	2022-12-29 20:10:49.000000000 +0000
+++ src/hunspell/hunzip.hxx
@@ -41,6 +41,10 @@
 #ifndef HUNZIP_HXX_
 #define HUNZIP_HXX_
 
+#ifdef __SUNPRO_CC
+#include <iostream>
+#endif
+
 #include "hunvisapi.h"
 
 #include <cstdio>
