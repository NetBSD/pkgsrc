$NetBSD: patch-src_scripts_tet_start.sh,v 1.2 2016/03/15 12:15:26 wiz Exp $

Fix shebang.

--- src/scripts/tet_start.sh.orig	2011-12-11 11:02:59.580983000 +0000
+++ src/scripts/tet_start.sh
@@ -1,9 +1,4 @@
-# -START-UNIX-ONLY-
 #!/bin/ksh
-# -END-UNIX-ONLY-
-# -START-WIN32-ONLY-
-: use the MKS shell
-# -END-WIN32-ONLY-
 #
 #	SCCS: @(#)tet_start.sh	1.1 (98/08/28)
 #
