$NetBSD: patch-postscript_buildtables_buildtables.sh,v 1.1 2015/08/22 20:51:31 leot Exp $

Make executeable

--- postscript/buildtables/buildtables.sh.orig	2015-05-19 16:10:39.000000000 +0200
+++ postscript/buildtables/buildtables.sh	2015-05-19 16:10:52.000000000 +0200
@@ -1,3 +1,4 @@
+#!/bin/sh
 #
 # Builds one or more font width tables or the typesetter description
 # file on a PostScript printer. Assumes you have direct access to the
