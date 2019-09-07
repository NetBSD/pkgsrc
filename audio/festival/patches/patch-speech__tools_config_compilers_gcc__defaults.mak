$NetBSD: patch-speech__tools_config_compilers_gcc__defaults.mak,v 1.2 2019/09/07 13:00:48 nia Exp $

--- speech_tools/config/compilers/gcc_defaults.mak.orig	2017-09-04 15:54:03.000000000 +0000
+++ speech_tools/config/compilers/gcc_defaults.mak
@@ -38,17 +38,11 @@
  ##                                                                       ##
  ###########################################################################
 
-CC=gcc
-CXX=gcc
-ifeq ($(OSTYPE),Darwin)
-CXX=g++
-endif
-
 COMPILER_DESC=FSF gcc
 COMPILER_VERSION_COMMAND=$(CXX) -v 2>&1 | tail -1 | sed -e 's/^....//'
 
-CFLAGS  = $(GCC_SYSTEM_OPTIONS) $(CC_OTHER_FLAGS)
-CXXFLAGS  =  $(GCC_SYSTEM_OPTIONS) -fno-implicit-templates $(CC_OTHER_FLAGS) $(OMP_OPTS) $(OMP_DEFS)
+CFLAGS  += $(GCC_SYSTEM_OPTIONS) $(CC_OTHER_FLAGS)
+CXXFLAGS  +=  $(GCC_SYSTEM_OPTIONS) -fno-implicit-templates $(CC_OTHER_FLAGS) $(OMP_OPTS) $(OMP_DEFS)
 
 DEBUG_CCFLAGS   = -g
 DEBUG_CXXFLAGS  = -g
@@ -100,7 +94,7 @@ TEMPLATE_ARGS = 
 ## The -lgcc here is redundant - gcc does this anyway - but it
 ## helps java know what needs to be loaded.
 
-COMPILERLIBS= $(COMPILER_LIBS_DIR:%=-L%) -lstdc++ $(OMP_OPTS)
+COMPILERLIBS= $(COMPILER_LIBS_DIR:%=-L%) $(OMP_OPTS)
 
 ## special ways of doing things, blank means default
 
