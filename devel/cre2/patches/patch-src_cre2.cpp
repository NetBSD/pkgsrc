$NetBSD: patch-src_cre2.cpp,v 1.4 2026/01/18 09:17:48 wiz Exp $

Add missing header for strlen().

--- src/cre2.cpp.orig	2026-01-18 09:16:30.360014220 +0000
+++ src/cre2.cpp
@@ -18,6 +18,7 @@
 
 #include <cstdlib>
 #include <cstdio>
+#include <cstring>
 #include <vector>
 
 
