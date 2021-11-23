$NetBSD: patch-Config_installfns.sh,v 1.1 2021/11/23 19:42:43 pho Exp $

Do not install backup files. This is pkgsrc-specific.

--- Config/installfns.sh.orig	2021-11-23 19:34:17.385780757 +0000
+++ Config/installfns.sh
@@ -18,6 +18,7 @@ for file in $allfuncs; do
   if test -f $sdir_top/$file; then
     case "$file" in
       */CVS/*) continue;;
+      *.orig) continue;;
     esac
     if test x$FUNCTIONS_SUBDIRS != x && test x$FUNCTIONS_SUBDIRS != xno; then
       case "$file" in
