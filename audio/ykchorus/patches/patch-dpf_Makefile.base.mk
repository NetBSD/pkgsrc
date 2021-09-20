$NetBSD: patch-dpf_Makefile.base.mk,v 1.1 2021/09/20 07:50:07 nia Exp $

Do not force -O2.

--- dpf/Makefile.base.mk.orig	2018-12-18 15:27:28.000000000 +0000
+++ dpf/Makefile.base.mk
@@ -105,7 +105,7 @@ endif
 
 ifeq ($(NOOPT),true)
 # No CPU-specific optimization flags
-BASE_OPTS  = -O2 -ffast-math -fdata-sections -ffunction-sections
+BASE_OPTS  = -ffast-math -fdata-sections -ffunction-sections
 endif
 
 ifeq ($(WIN32),true)
