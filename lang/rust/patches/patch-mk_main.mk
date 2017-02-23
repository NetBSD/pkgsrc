$NetBSD: patch-mk_main.mk,v 1.1 2017/02/23 09:35:16 jperkin Exp $

Specify full path to stage0 to work around NetBSD $ORIGIN issues.

--- mk/main.mk.orig	2017-02-09 01:37:48.000000000 +0000
+++ mk/main.mk
@@ -398,7 +398,7 @@ define SREQ
 
 # Destinations of artifacts for the host compiler
 HROOT$(1)_H_$(3) = $(3)/stage$(1)
-HBIN$(1)_H_$(3) = $$(HROOT$(1)_H_$(3))/bin
+HBIN$(1)_H_$(3) = $$(CURDIR)/$$(HROOT$(1)_H_$(3))/bin
 
 ifeq ($$(CFG_WINDOWSY_$(3)),1)
 # On Windows we always store host runtime libraries in the 'bin' directory because
