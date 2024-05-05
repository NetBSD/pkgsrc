$NetBSD: patch-source_darkplaces_makefile.inc,v 1.2 2024/05/05 09:31:37 nia Exp $

Allow pkgsrc to set LDFLAGS.

--- source/darkplaces/makefile.inc.orig	2023-04-30 09:22:32.000000000 +0000
+++ source/darkplaces/makefile.inc
@@ -197,7 +197,7 @@ OPTIM_DEBUG=$(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing -funroll-loops $(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing $(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O3 -fno-strict-aliasing $(CPUOPTIMIZATIONS)
-OPTIM_RELEASE=-O3 -fno-strict-aliasing -fno-math-errno -fno-trapping-math $(CPUOPTIMIZATIONS)
+OPTIM_RELEASE=$(CFLAGS) -fno-strict-aliasing -fno-math-errno -fno-trapping-math $(CPUOPTIMIZATIONS)
 # NOTE: *never* *ever* use the -ffast-math or -funsafe-math-optimizations flag
 # Also, since gcc 5, -ffinite-math-only makes NaN and zero compare equal inside engine code but not inside QC, which causes error spam for seemingly valid QC code like if (x != 0) return 1 / x;
 
@@ -214,7 +214,7 @@ LDFLAGS_RELEASE=$(OPTIM_RELEASE) -DSVNRE
 
 OBJ_GLX= builddate.c sys_linux.o vid_glx.o thread_pthread.o keysym2ucs.o $(OBJ_MENU) $(OBJ_SOUND) $(OBJ_CD) $(OBJ_VIDEO_CAPTURE) $(OBJ_COMMON)
 
-LDFLAGS_UNIXCOMMON=-lm $(LIB_ODE) $(LIB_Z) $(LIB_JPEG) $(LIB_CRYPTO) $(LIB_CRYPTO_RIJNDAEL)
+LDFLAGS_UNIXCOMMON=$(LDFLAGS) -lm $(LIB_ODE) $(LIB_Z) $(LIB_JPEG) $(LIB_CRYPTO) $(LIB_CRYPTO_RIJNDAEL)
 LDFLAGS_UNIXCL=-L$(UNIX_X11LIBPATH) -lX11 -lXpm -lXext -lXxf86vm -pthread $(LIB_SOUND)
 LDFLAGS_UNIXCL_PRELOAD=-lz -ljpeg -lpng -logg -ltheora -lvorbis -lvorbisenc -lvorbisfile -lcurl
 LDFLAGS_UNIXSV_PRELOAD=-lz -ljpeg -lpng -lcurl
