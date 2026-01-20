$NetBSD: patch-test_demo__new__pair.c,v 1.1 2026/01/20 10:07:04 wiz Exp $

Upstream bugfix.
Id: demo_new_pair.c,v 1.35 2026/01/10 20:36:29 tom Exp

--- test/demo_new_pair.c.orig	2026-01-20 10:04:56.971698718 +0000
+++ test/demo_new_pair.c
@@ -167,7 +167,7 @@ main(int argc, char *argv[])
 int
 main(int argc, char *argv[])
 {
-    static const char *help[] =
+    static NCURSES_CONST char *help[] =
     {
 	"This program iterates over the possible color combinations,",
 	"allocating or initializing color pairs.  For best results,",
