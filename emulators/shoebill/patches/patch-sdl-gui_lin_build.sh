$NetBSD: patch-sdl-gui_lin_build.sh,v 1.1 2016/03/23 14:21:03 hauke Exp $

Make build parameters settable from pkg Makefile

--- sdl-gui/lin_build.sh.orig	2015-09-14 02:11:18.000000000 +0000
+++ sdl-gui/lin_build.sh
@@ -1,6 +1,7 @@
-#!/bin/bash
+#!/bin/sh
 
-CC=gcc
+CC=${CC:-"gcc"}
+CFLAGS=${CFLAGS:-"-O2"}
 
 files=""
 for i in adb fpu mc68851 mem via floppy core_api cpu dis; do
@@ -17,6 +18,6 @@ $CC -O1 ../core/decoder_gen.c -o decoder
 ./decoder_gen dis .
 
 
-cmd="$CC -O3 -ggdb -flto $files sdl.c -lpthread -lm -lSDL2 -lGL -o shoebill"
+cmd="$CC ${CFLAGS} -ggdb -flto $files sdl.c -lpthread -lm -lSDL2 -lGL ${LDFLAGS} -o shoebill"
 echo $cmd
 $cmd
