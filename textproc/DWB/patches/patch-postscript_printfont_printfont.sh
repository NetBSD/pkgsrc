$NetBSD: patch-postscript_printfont_printfont.sh,v 1.1 2015/08/22 20:51:31 leot Exp $

Make executeable

--- postscript/printfont/printfont.sh.orig	2015-05-19 16:27:00.000000000 +0200
+++ postscript/printfont/printfont.sh	2015-05-19 16:27:10.000000000 +0200
@@ -1,3 +1,4 @@
+#!/bin/sh
 #
 # Formatted dump of encoded characters in one or more PostScript fonts.
 # Arguments should be PostScript font names or the word all, which dumps
