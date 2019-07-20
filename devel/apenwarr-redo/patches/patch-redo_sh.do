$NetBSD: patch-redo_sh.do,v 1.1 2019/07/20 21:17:11 schmonz Exp $

Look for pkgsrc-provided dash.

--- redo/sh.do.orig	2019-01-02 19:49:33.000000000 +0000
+++ redo/sh.do
@@ -11,7 +11,7 @@ WARN=
 # powerful ones.  We want weaker shells to take precedence, as long as they
 # pass the tests, because weaker shells are more likely to point out when you
 # use some non-portable feature.
-for sh in dash /usr/xpg4/bin/sh ash posh \
+for sh in ${PREFIX}/bin/dash /usr/xpg4/bin/sh ash posh \
 		lksh mksh ksh ksh88 ksh93 pdksh \
 		zsh bash busybox /bin/sh; do
 	printf " %-22s" "$sh..."
