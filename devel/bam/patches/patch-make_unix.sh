$NetBSD: patch-make_unix.sh,v 1.1 2015/09/12 18:51:07 wiz Exp $

===========================================================================
This patch avoids compiling bam with -ldl because the BSDs have it in libc.

Upstream has already addressed this in their development branch, so this
patch should become unnecessary with later versions.
===========================================================================


--- make_unix.sh.orig	2010-08-09 20:08:24.000000000 +0200
+++ make_unix.sh	2015-09-12 03:56:22.000000000 +0200
@@ -1,4 +1,10 @@
 #!/bin/sh
 gcc -Wall -ansi -pedantic src/tools/txt2c.c -o src/tools/txt2c
 src/tools/txt2c src/base.lua src/tools.lua src/driver_gcc.lua src/driver_cl.lua > src/internal_base.h
-gcc -Wall -ansi -pedantic src/*.c src/lua/*.c -o bam -I src/lua -lm -lpthread -ldl -O2 -rdynamic $*
+
+case "$(uname)" in
+	*BSD) ldl=       ;;
+	   *) ldl='-ldl' ;;
+esac
+
+gcc -Wall -ansi -pedantic src/*.c src/lua/*.c -o bam -I src/lua -lm -lpthread $ldl -O2 -rdynamic $*
