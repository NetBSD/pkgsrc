$NetBSD: patch-nss_coreconf_OpenBSD.mk,v 1.4 2021/05/01 21:52:02 wiz Exp $

* Use non-versioned libraries for OpenBSD too

--- nss/coreconf/OpenBSD.mk.orig	2021-04-15 16:17:44.000000000 +0000
+++ nss/coreconf/OpenBSD.mk
@@ -24,7 +24,7 @@ OS_LIBS			+= -pthread
 DSO_LDOPTS		+= -pthread
 endif
 
-DLL_SUFFIX		= so.1.0
+DLL_SUFFIX		= so
 
 OS_CFLAGS		= $(DSO_CFLAGS) $(OS_REL_CFLAGS) -Wall -Wno-switch -pipe -DOPENBSD
 
