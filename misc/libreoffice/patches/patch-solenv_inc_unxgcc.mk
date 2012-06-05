$NetBSD: patch-solenv_inc_unxgcc.mk,v 1.1 2012/06/05 21:53:42 wiz Exp $

Using -std=gnu++0x instead of -std=c++0x may avoid
crashes on NetBSD and OpenBSD

Upstream bug report:
https://bugs.freedesktop.org/show_bug.cgi?id=48134

--- solenv/inc/unxgcc.mk.orig	2012-05-22 12:48:18.000000000 +0000
+++ solenv/inc/unxgcc.mk
@@ -88,7 +88,7 @@ CFLAGSCXX= -pipe $(ARCH_FLAGS)
 CFLAGSCXX+=-fvisibility-inlines-hidden
 .ENDIF # "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
 .IF "$(HAVE_CXX0X)" == "TRUE"
-CFLAGSCXX+=-std=c++0x
+CFLAGSCXX+=-std=gnu++0x
 .IF "$(GCCNUMVER)" <= "000400059999"
 CFLAGSCXX+=-Wno-deprecated-declarations
 .ENDIF
