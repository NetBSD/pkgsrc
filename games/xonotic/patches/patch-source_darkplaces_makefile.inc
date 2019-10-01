$NetBSD: patch-source_darkplaces_makefile.inc,v 1.1 2019/10/01 12:32:26 nia Exp $

Allow pkgsrc to set LDFLAGS.

--- source/darkplaces/makefile.inc.orig	2017-04-01 13:26:56.000000000 +0000
+++ source/darkplaces/makefile.inc
@@ -209,7 +209,7 @@ LDFLAGS_RELEASE=$(OPTIM_RELEASE) -DSVNRE
 
 OBJ_GLX= builddate.c sys_linux.o vid_glx.o thread_pthread.o keysym2ucs.o $(OBJ_MENU) $(OBJ_SOUND) $(OBJ_CD) $(OBJ_VIDEO_CAPTURE) $(OBJ_COMMON)
 
-LDFLAGS_UNIXCOMMON=-lm $(LIB_ODE) $(LIB_Z) $(LIB_JPEG) $(LIB_CRYPTO) $(LIB_CRYPTO_RIJNDAEL)
+LDFLAGS_UNIXCOMMON=$(LDFLAGS) -lm $(LIB_ODE) $(LIB_Z) $(LIB_JPEG) $(LIB_CRYPTO) $(LIB_CRYPTO_RIJNDAEL)
 LDFLAGS_UNIXCL=-L$(UNIX_X11LIBPATH) -lX11 -lXpm -lXext -lXxf86vm -pthread $(LIB_SOUND)
 LDFLAGS_UNIXCL_PRELOAD=-lz -ljpeg -lpng -logg -ltheora -lvorbis -lvorbisenc -lvorbisfile -lcurl
 LDFLAGS_UNIXSV_PRELOAD=-lz -ljpeg -lpng -lcurl
