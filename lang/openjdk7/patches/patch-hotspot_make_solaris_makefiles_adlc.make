$NetBSD: patch-hotspot_make_solaris_makefiles_adlc.make,v 1.1 2013/06/15 09:31:05 jperkin Exp $

GCC support.

--- hotspot/make/solaris/makefiles/adlc.make.orig	2013-02-19 23:21:59.000000000 +0000
+++ hotspot/make/solaris/makefiles/adlc.make
@@ -75,9 +75,11 @@ endif
 
 # CFLAGS_WARN holds compiler options to suppress/enable warnings.
 # Compiler warnings are treated as errors
+ifeq ("${Platform_compiler}", "sparcWorks")
 ifeq ($(shell expr $(COMPILER_REV_NUMERIC) \>= 509), 1)
   CFLAGS_WARN = +w -errwarn
 endif
+endif
 CFLAGS += $(CFLAGS_WARN)
 
 ifeq ("${Platform_compiler}", "sparcWorks")
