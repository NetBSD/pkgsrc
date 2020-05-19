$NetBSD: patch-src_dstrings.c,v 1.1 2020/05/19 11:20:16 micha Exp $

Print note that this is a patched version to terminal.

--- src/dstrings.c.orig	2020-05-15 09:47:31.000000000 +0000
+++ src/dstrings.c
@@ -542,6 +542,11 @@ char *text[NUMTEXT] = {
     "get a copy of the original game, call 1-800-IDGAMES or see the readme file.\n"
     "        You will not receive technical support for modified games.\n"
     "                      press enter to continue\n"
+    "===========================================================================\n"
+    "===========================================================================\n"
+    "Note for pkgsrc: This version uses patches for additional features:\n"
+    "- Support for extended nodes (DeeP V4 and ZDoom, Feature request #95)\n"
+    "- Support for \"-blockmap\" command line option (create blockmap internally)\n"
     "===========================================================================\n",
 
   // SHAREWARE
