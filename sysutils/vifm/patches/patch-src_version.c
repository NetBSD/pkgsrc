$NetBSD: patch-src_version.c,v 1.1 2026/01/01 19:41:35 wiz Exp $

Add missing header for tigetflag().

--- src/version.c.orig	2026-01-01 19:34:45.284775282 +0000
+++ src/version.c
@@ -19,6 +19,7 @@
 #include "version.h"
 
 #include <curses.h> /* COLORS COLOR_PAIRS */
+#include <term.h> /* tigetflag */
 
 #include <assert.h> /* assert() */
 #include <stddef.h> /* NULL */
