$NetBSD: patch-codegenerator.mk,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- codegenerator.mk.orig	2015-10-19 06:31:15.000000000 +0000
+++ codegenerator.mk
@@ -6,7 +6,7 @@ ifeq ($(JAVA),)
 JAVA = java-not-found
 endif
 
-SWIG ?= $(shell which swig)
+SWIG ?= $(shell which swig2.0)
 ifeq ($(SWIG),)
 SWIG = swig-not-found
 endif
