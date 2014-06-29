$NetBSD: patch-vfu_vfuopt.cpp,v 1.1 2014/06/29 19:43:54 dholland Exp $

Sprinkle const to make more modern C++ compilers happier.

--- vfu/vfuopt.cpp.orig	2002-05-17 08:48:41.000000000 +0000
+++ vfu/vfuopt.cpp
@@ -18,13 +18,13 @@
 
 Options opt;
 
-char *NOYES[] = { " - ", "YES", NULL };
-char *NOYESPRECOPY[] = { " - ", "YES", "PRELIM", NULL };
-char *FTIMETYPE[] = { "CHANGE", "MODIFY", "ACCESS", NULL };
+const char *const NOYES[] = { " - ", "YES", NULL };
+const char *const NOYESPRECOPY[] = { " - ", "YES", "PRELIM", NULL };
+const char *const FTIMETYPE[] = { "CHANGE", "MODIFY", "ACCESS", NULL };
 #ifdef _TARGET_GO32_
-char *TAGMARKS[] = { ">>", "=>", "->", "Í", "Ä", " ¯", "¯¯", NULL };
+const char *const TAGMARKS[] = { ">>", "=>", "->", "Í", "Ä", " ¯", "¯¯", NULL };
 #else
-char *TAGMARKS[] = { ">>", "=>", "->", NULL };
+const char *const TAGMARKS[] = { ">>", "=>", "->", NULL };
 #endif
 
 ToggleEntry Toggles[] =
