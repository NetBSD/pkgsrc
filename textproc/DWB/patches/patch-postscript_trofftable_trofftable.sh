$NetBSD: patch-postscript_trofftable_trofftable.sh,v 1.1 2015/08/22 20:51:31 leot Exp $

Make executeable

--- postscript/trofftable/trofftable.sh.orig	2015-05-19 16:31:03.000000000 +0200
+++ postscript/trofftable/trofftable.sh	2015-05-19 16:31:23.000000000 +0200
@@ -1,3 +1,4 @@
+#!/bin/sh
 #
 # Writes a PostScript program on standard output that builds a width
 # table or typesetter description file. The program uses PostScript's
