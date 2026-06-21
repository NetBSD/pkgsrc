$NetBSD: patch-color.c,v 1.3 2026/06/21 07:31:00 tron Exp $

Fix build under NetBSD

--- color.c.orig	2026-06-12 06:03:22.000000000 +0100
+++ color.c	2026-06-21 08:25:36.282919578 +0100
@@ -133,7 +133,7 @@
 
 #define COLOR_QUOTE_INIT        8
 
-#ifdef NCURSES_VERSION
+#if defined(NCURSES_VERSION) || (defined(__NetBSD__) && !defined(USE_SLANG_CURSES))
 #define ATTR_MASK (A_ATTRIBUTES ^ A_COLOR)
 #elif defined(USE_SLANG_CURSES)
 #define ATTR_MASK (~(unsigned int)A_NORMAL ^ (A_CHARTEXT | A_UNUSED | A_COLOR))
