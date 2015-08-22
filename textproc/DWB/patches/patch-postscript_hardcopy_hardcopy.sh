$NetBSD: patch-postscript_hardcopy_hardcopy.sh,v 1.1 2015/08/22 20:51:31 leot Exp $

Make executeable

--- postscript/hardcopy/hardcopy.sh.orig	2015-05-19 16:18:11.000000000 +0200
+++ postscript/hardcopy/hardcopy.sh	2015-05-19 16:18:28.000000000 +0200
@@ -1,3 +1,4 @@
+#!/bin/sh
 #
 # Generate paper output from the data that a PostScript program normally
 # sends back to a host computer using file output operators.
