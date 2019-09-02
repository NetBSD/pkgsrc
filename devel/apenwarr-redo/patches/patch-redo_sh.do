$NetBSD: patch-redo_sh.do,v 1.2 2019/09/02 18:20:50 schmonz Exp $

Look for pkgsrc-provided dash only.

--- redo/sh.do.orig	2019-01-02 19:49:33.000000000 +0000
+++ redo/sh.do
@@ -11,9 +11,7 @@ WARN=
 # powerful ones.  We want weaker shells to take precedence, as long as they
 # pass the tests, because weaker shells are more likely to point out when you
 # use some non-portable feature.
-for sh in dash /usr/xpg4/bin/sh ash posh \
-		lksh mksh ksh ksh88 ksh93 pdksh \
-		zsh bash busybox /bin/sh; do
+for sh in ${PREFIX}/bin/dash; do
 	printf " %-22s" "$sh..."
 	FOUND=`which $sh 2>/dev/null` || { echo "missing"; continue; }
 	
