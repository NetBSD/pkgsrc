$NetBSD: patch-src_misc.cc,v 1.4 2024/03/17 13:55:11 wiz Exp $

Add header for setlocale().

--- src/misc.cc.orig	2024-03-06 15:56:22.000000000 +0000
+++ src/misc.cc
@@ -29,6 +29,7 @@
 #include <memory>
 
 #include <langinfo.h>
+#include <locale.h>
 #include <pwd.h>
 
 #include <config.h>
