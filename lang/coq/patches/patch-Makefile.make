$NetBSD: patch-Makefile.make,v 1.1 2021/02/09 22:37:43 dholland Exp $

Use correct find(1) syntax.

--- Makefile.make~	2020-12-11 08:46:08.000000000 +0000
+++ Makefile.make
@@ -48,7 +48,7 @@
 # !! FIND_SKIP_DIRS section of dev/doc/build-system.dev.txt         !!
 # "-not -name ." to avoid skipping everything since we "find ."
 # "-type d" to be able to find .merlin.in files
-FIND_SKIP_DIRS:=-not -name . '(' \
+FIND_SKIP_DIRS:=! -name . '(' \
   -name '{arch}' -o \
   -name '.*' -type d -o \
   -name '_darcs' -o \
