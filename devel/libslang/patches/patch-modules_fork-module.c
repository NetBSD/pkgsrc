$NetBSD: patch-modules_fork-module.c,v 1.1 2025/01/06 21:36:25 ktnb Exp $

--- modules/fork-module.c.orig	2009-12-05 19:03:51.000000000 +0000
+++ modules/fork-module.c
@@ -275,7 +275,9 @@ static SLang_IConstant_Type Module_ICons
 {
    MAKE_ICONSTANT("WNOHANG", WNOHANG),
    MAKE_ICONSTANT("WUNTRACED", WUNTRACED),
+#ifdef WCONTINUED
    MAKE_ICONSTANT("WCONTINUED", WCONTINUED),
+#endif
    SLANG_END_ICONST_TABLE
 };
 
