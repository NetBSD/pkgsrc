$NetBSD: patch-src_Mk-nbx86.mk,v 1.1 2013/10/17 15:41:10 ryoon Exp $

http://www.falu.nl/~rhialto/klh-diffs2

--- src/Mk-nbx86.mk.orig	2002-04-25 22:56:48.000000000 +0000
+++ src/Mk-nbx86.mk
@@ -21,7 +21,7 @@
 
 # Build definitions
 SRC = ../../src
-CFLAGS = -c -g3 -O3
+CFLAGS += -c -g3 -O3
 CFLAGS_LINT = -ansi -pedantic -Wall -Wshadow \
 		-Wstrict-prototypes -Wmissing-prototypes \
 		-Wmissing-declarations -Wredundant-decls
