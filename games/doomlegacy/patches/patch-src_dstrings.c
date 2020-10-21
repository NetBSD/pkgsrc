$NetBSD: patch-src_dstrings.c,v 1.2 2020/10/21 11:43:31 micha Exp $

Print note that this is a patched version to terminal.

--- src/dstrings.c.orig	2020-07-07 09:01:41.000000000 +0000
+++ src/dstrings.c
@@ -542,6 +542,12 @@ char *text[NUMTEXT] = {
     "get a copy of the original game, call 1-800-IDGAMES or see the readme file.\n"
     "        You will not receive technical support for modified games.\n"
     "                      press enter to continue\n"
+    "===========================================================================\n"
+    "===========================================================================\n"
+    "Note for pkgsrc: This version uses pkgsrc patches for additional features:\n"
+    "- Support for extended nodes (DeeP V4 and ZDoom, Feature request #95)\n"
+    "- Support for \"-blockmap\" command line option (create blockmap internally,\n"
+    "  Feature request #96)\n"
     "===========================================================================\n",
 
   // SHAREWARE
