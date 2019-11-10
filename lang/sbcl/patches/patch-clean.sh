$NetBSD: patch-clean.sh,v 1.1 2019/11/10 16:58:31 he Exp $

Don't remove original files after patching.

--- clean.sh.orig	2019-09-28 09:49:01.000000000 +0000
+++ clean.sh
@@ -84,7 +84,6 @@ find . \( \
         -name '*~' -o \
         -name '#*#' -o \
         -name '.#*' -o \
-        -name '*.orig' -o \
         -name '.*.orig' -o \
         -name '*.rej' -o \
         -name '?*.x86f' -o \
