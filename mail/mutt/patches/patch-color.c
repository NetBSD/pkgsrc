$NetBSD: patch-color.c,v 1.1 2020/11/08 17:42:45 tron Exp $

Fix build under NetBSD

--- color.c.orig	2020-11-03 17:50:37.000000000 +0000
+++ color.c	2020-11-08 16:39:21.085043268 +0000
@@ -119,7 +119,7 @@
 
 #define COLOR_QUOTE_INIT	8
 
-#ifdef NCURSES_VERSION
+#if defined(NCURSES_VERSION) || defined(__NetBSD__)
 #define ATTR_MASK (A_ATTRIBUTES ^ A_COLOR)
 #elif defined (USE_SLANG_CURSES)
 #define ATTR_MASK (~(unsigned int)A_NORMAL ^ (A_CHARTEXT | A_UNUSED | A_COLOR))
