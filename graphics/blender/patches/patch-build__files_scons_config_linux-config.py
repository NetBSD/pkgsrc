$NetBSD: patch-build__files_scons_config_linux-config.py,v 1.2 2015/12/15 09:46:27 markd Exp $

--- build_files/scons/config/linux-config.py.orig	2015-03-30 23:32:22.000000000 +0000
+++ build_files/scons/config/linux-config.py
@@ -175,7 +175,7 @@ BF_JEMALLOC_LIBPATH = '${BF_JEMALLOC}/li
 BF_JEMALLOC_LIB = 'jemalloc'
 BF_JEMALLOC_LIB_STATIC = '${BF_JEMALLOC_LIBPATH}/libjemalloc.a'
 
-WITH_BF_OIIO = False
+WITH_BF_OIIO = True
 WITH_BF_STATICOIIO = False
 BF_OIIO = '/usr'
 BF_OIIO_INC = '${BF_OIIO}/include'
@@ -215,7 +215,7 @@ WITH_BF_RAYOPTIMIZATION = True
 BF_RAYOPTIMIZATION_SSE_FLAGS = ['-msse','-pthread']
 
 #SpaceNavigator and friends
-WITH_BF_3DMOUSE = True
+WITH_BF_3DMOUSE = False
 WITH_BF_STATIC3DMOUSE = False
 BF_3DMOUSE = '/usr'
 BF_3DMOUSE_INC = '${BF_3DMOUSE}/include'
@@ -261,6 +261,7 @@ BF_INSTALLDIR='../install/linux'
 
 #Link against pthread
 PLATFORM_LINKFLAGS = ['-pthread']
+PLATFORM_LINKFLAGS += ['-Wl,-R${BF_OPENEXR}/lib']
 
 #Fix for LLVM conflict with Mesa llvmpipe, SDL dynload also requires symbols to be hidden.
 # TODO(sergey): Move this to SConstruct, so we can have this line depended on user config.
