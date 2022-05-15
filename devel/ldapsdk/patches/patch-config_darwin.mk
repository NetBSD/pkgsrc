$NetBSD: patch-config_darwin.mk,v 1.1 2022/05/15 02:19:36 dholland Exp $

Halfassed attempt at a config for MacOS based on the existing one for
Rhapsody (aka prelease MacOS from 25 years ago) -- probably won't
work, but will work better than the prior state of not having one at
all.

--- config/Darwin.mk.orig	2022-05-15 02:08:50.742530570 +0000
+++ config/Darwin.mk
@@ -23,11 +23,11 @@
 # Version-independent
 ######################################################################
 
-ARCH			:= rhapsody
+ARCH			:= darwin
 ifeq (86,$(findstring 86,$(OS_TEST)))
 CPU_ARCH		:= i386
 else
-CPU_ARCH		:= ppc
+CPU_ARCH		:= $(OS_TEST)
 endif
 GFX_ARCH		:=
 
@@ -92,14 +92,12 @@ endif
 CC			= cc
 AR			= libtool -static -o $@
 
-EMACS			= /usr/bin/emacs
-PERL			= /usr/bin/perl
+EMACS			= /usr/bin/true
 RANLIB			= ranlib
 
 LDFLAGS			= 
 
-# -nostdlib gets around the missing -lm problem.
-DSO_LDFLAGS		= -arch $(CPU_ARCH) -dynamiclib -nostdlib -lstdc++ -lcc_dynamic -compatibility_version 1 -current_version 1 -all_load -undefined suppress
+DSO_LDFLAGS		=
 
 # Comment out MKSHLIB to build only static libraries.
 MKSHLIB			= $(CC) $(DSO_LDFLAGS)
