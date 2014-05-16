$NetBSD: patch-nss_coreconf_OpenBSD.mk,v 1.1 2014/05/16 12:38:01 ryoon Exp $

--- nss/coreconf/OpenBSD.mk.orig	2014-03-14 20:31:59.000000000 +0000
+++ nss/coreconf/OpenBSD.mk
@@ -24,7 +24,7 @@ OS_LIBS			+= -pthread
 DSO_LDOPTS		+= -pthread
 endif
 
-DLL_SUFFIX		= so.1.0
+DLL_SUFFIX		= so
 
 OS_CFLAGS		= $(DSO_CFLAGS) $(OS_REL_CFLAGS) -ansi -Wall -Wno-switch -pipe -DOPENBSD
 
