$NetBSD: patch-gcc_config_rs6000_morphos.h,v 1.1 2021/07/25 15:06:25 js Exp $

Don't try to unconditionally pull in -latomic - it will make the bootstrap
compiler require -latomic, which of course means we can never have a compiler
to build libatomic.

--- gcc/config/rs6000/morphos.h.orig	2021-07-25 14:52:44.485678708 +0000
+++ gcc/config/rs6000/morphos.h
@@ -258,7 +258,7 @@ mclib=default|!mclib=*: %(endfile_morpho
 
 
 #undef LIB_SPEC
-#define LIB_SPEC "%{!nostdlib: -L/gg/lib -L/gg/usr/lib} --start-group -lc -labox -laboxstubs -lsavl -latomic %{mclib=libnix: -lauto} --end-group"
+#define LIB_SPEC "%{!nostdlib: -L/gg/lib -L/gg/usr/lib} --start-group -lc -labox -laboxstubs -lsavl %{mclib=libnix: -lauto} --end-group"
 
 #undef SUBTARGET_EXTRA_SPECS
 #define SUBTARGET_EXTRA_SPECS \
