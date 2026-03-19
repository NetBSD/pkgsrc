$NetBSD: patch-gram.y,v 1.1 2026/03/19 08:48:20 nia Exp $

Fix implicit function declarations.

--- gram.y.orig	2026-03-19 08:04:31.109553700 +0000
+++ gram.y
@@ -16,6 +16,7 @@
 
 %{
 #include <stdlib.h>
+#include <string.h>
 #include <limits.h>
 
 #ifdef USELOCALE
