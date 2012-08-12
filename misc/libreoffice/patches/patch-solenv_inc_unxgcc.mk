$NetBSD: patch-solenv_inc_unxgcc.mk,v 1.2 2012/08/12 15:55:56 wiz Exp $

Using -std=gnu++0x instead of -std=c++0x may avoid
crashes on NetBSD and OpenBSD

Upstream bug report:
https://bugs.freedesktop.org/show_bug.cgi?id=48134

--- solenv/inc/unxgcc.mk.orig	2012-06-26 13:50:03.000000000 +0000
+++ solenv/inc/unxgcc.mk
@@ -88,7 +88,7 @@ CFLAGSCXX= -pipe $(ARCH_FLAGS)
 CFLAGSCXX+=-fvisibility-inlines-hidden
 .ENDIF # "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
 .IF "$(HAVE_CXX0X)" == "TRUE"
-CFLAGSCXX+=-std=c++0x
+CFLAGSCXX+=-std=gnu++0x
 CFLAGSCXX+=-Wno-deprecated-declarations -Wno-deprecated
 .ENDIF # "$(HAVE_CXX0X)" == "TRUE"
 
