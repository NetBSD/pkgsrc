$NetBSD: patch-src_Makefile.inc,v 1.1 2023/02/25 17:55:24 ryoon Exp $

* Linux and the other Unix-like OSes should use CC as linker.

--- src/Makefile.inc.orig	2014-08-28 11:45:21.000000000 +0000
+++ src/Makefile.inc
@@ -62,10 +62,10 @@ UNAME_S := $(shell sh -c 'uname -s 2>/de
 # because maintaining the nesting to match is a pain.  If
 # we had "elif" things would have been much nicer...
 
-ifeq ($(UNAME_S),Linux)
+ifeq ($(UNAME_S), $(filter LINUX %BSD SOLARIS, $(UNAME_S)))
 	CPP=cpp -P -traditional -Dunix -Umsdos
 	STRIP=strip -S
-	LD=gcc -rdynamic -Wl,-rpath,$(LIBDIR)
+	LD=$(CC) -rdynamic -Wl,-rpath,$(LIBDIR)
 	DYNLD=gcc -shared
 endif
 ifeq ($(UNAME_S),Darwin) 	# For MacOS X, use the same as Linux except DYNDL
