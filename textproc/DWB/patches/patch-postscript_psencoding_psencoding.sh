$NetBSD: patch-postscript_psencoding_psencoding.sh,v 1.1 2015/08/22 20:51:31 leot Exp $

Make executeable

--- postscript/psencoding/psencoding.sh.orig	2015-05-19 16:29:23.000000000 +0200
+++ postscript/psencoding/psencoding.sh	2015-05-19 16:29:32.000000000 +0200
@@ -1,3 +1,4 @@
+#!/bin/sh
 #
 # Trivial script for checking and setting the default PostScript font
 # encoding. Changing the default assumes you can write in $POSTLIB.
