$NetBSD: patch-speech__tools_config_compilers_gcc__defaults.mak,v 1.1 2013/06/13 21:40:43 joerg Exp $

--- speech_tools/config/compilers/gcc_defaults.mak.orig	2010-02-03 12:28:14.000000000 +0000
+++ speech_tools/config/compilers/gcc_defaults.mak
@@ -39,10 +39,7 @@
  ###########################################################################
 
 CC=gcc
-CXX=gcc
-ifeq ($(OSTYPE),Darwin)
 CXX=g++
-endif
 
 COMPILER_DESC=FSF gcc
 COMPILER_VERSION_COMMAND=$(CXX) -v 2>&1 | tail -1 | sed -e 's/^....//'
@@ -98,7 +95,7 @@ TEMPLATE_ARGS = 
 ## The -lgcc here is redundant - gcc does this anyway - but it
 ## helps java know what needs to be loaded.
 
-COMPILERLIBS= $(COMPILER_LIBS_DIR:%=-L%) -lstdc++ -lgcc
+COMPILERLIBS= $(COMPILER_LIBS_DIR:%=-L%)
 
 ## special ways of doing things, blank means default
 
