$NetBSD: patch-Makefile.make,v 1.2 2022/06/21 02:21:22 dholland Exp $

Use correct find(1) syntax.

--- Makefile.make.orig	2022-05-31 08:36:38.000000000 +0000
+++ Makefile.make
@@ -48,7 +48,7 @@
 # !! FIND_SKIP_DIRS section of dev/doc/build-system.dev.txt         !!
 # "-not -name ." to avoid skipping everything since we "find ."
 # "-type d" to be able to find .merlin.in files
-FIND_SKIP_DIRS:=-not -name . '(' \
+FIND_SKIP_DIRS:=! -name . '(' \
   -name '.*' -type d -o \
   -name 'debian' -o \
   -name "$${GIT_DIR}" -o \
