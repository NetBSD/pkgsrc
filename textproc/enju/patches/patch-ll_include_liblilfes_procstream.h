$NetBSD: patch-ll_include_liblilfes_procstream.h,v 1.1 2026/09/15 07:22:27 wiz Exp $

Add missing header for close() etc.

--- ll/include/liblilfes/procstream.h.orig	2026-09-15 07:11:29.512476194 +0000
+++ ll/include/liblilfes/procstream.h
@@ -15,6 +15,7 @@
 #include <istream>
 #include <ostream>
 #include <string>
+#include <unistd.h>
 
 #ifdef LILFES_WIN_
 #include <Windows.h>
