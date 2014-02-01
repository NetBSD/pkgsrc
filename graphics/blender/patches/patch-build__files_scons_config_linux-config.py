$NetBSD: patch-build__files_scons_config_linux-config.py,v 1.1 2014/02/01 03:57:52 markd Exp $

--- ./build_files/scons/config/linux-config.py.orig	2013-02-07 14:10:01.000000000 +0000
+++ ./build_files/scons/config/linux-config.py
@@ -178,7 +178,7 @@ BF_JEMALLOC_LIBPATH = '${BF_JEMALLOC}/li
 BF_JEMALLOC_LIB = 'jemalloc'
 BF_JEMALLOC_LIB_STATIC = '${BF_JEMALLOC_LIBPATH}/libjemalloc.a'
 
-WITH_BF_OIIO = False
+WITH_BF_OIIO = True
 WITH_BF_STATICOIIO = False
 BF_OIIO = '/usr'
 BF_OIIO_INC = '${BF_OIIO}/include'
@@ -218,7 +218,7 @@ WITH_BF_RAYOPTIMIZATION = True
 BF_RAYOPTIMIZATION_SSE_FLAGS = ['-msse','-pthread']
 
 #SpaceNavigator and friends
-WITH_BF_3DMOUSE = True
+WITH_BF_3DMOUSE = False
 WITH_BF_STATIC3DMOUSE = False
 BF_3DMOUSE = '/usr'
 BF_3DMOUSE_INC = '${BF_3DMOUSE}/include'
