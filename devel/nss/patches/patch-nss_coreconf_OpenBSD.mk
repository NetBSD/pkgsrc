$NetBSD: patch-nss_coreconf_OpenBSD.mk,v 1.2 2016/05/25 13:17:13 ryoon Exp $

--- nss/coreconf/OpenBSD.mk.orig	2016-05-17 07:58:45.000000000 +0000
+++ nss/coreconf/OpenBSD.mk
@@ -24,7 +24,7 @@ OS_LIBS			+= -pthread
 DSO_LDOPTS		+= -pthread
 endif
 
-DLL_SUFFIX		= so.1.0
+DLL_SUFFIX		= so
 
 OS_CFLAGS		= $(DSO_CFLAGS) $(OS_REL_CFLAGS) -Wall -Wno-switch -pipe -DOPENBSD
 
