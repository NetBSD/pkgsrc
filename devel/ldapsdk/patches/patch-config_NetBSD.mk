$NetBSD: patch-config_NetBSD.mk,v 1.1 2022/09/17 17:17:44 he Exp $

--- config/NetBSD.mk.orig	1998-12-31 11:28:24.000000000 +0000
+++ config/NetBSD.mk
@@ -89,10 +89,10 @@ endif
 
 BUILD_UNIX_PLUGINS	= 1
 
-MKSHLIB			= $(LD) $(DSO_LDOPTS)
+MKSHLIB			= $(LD) $(DSO_LDOPTS) $(LDFLAGS)
 
 DSO_CFLAGS		= -fPIC
-DSO_LDFLAGS		= 
+DSO_LDFLAGS		= $(LDFLAGS)
 
 #
 # For NetBSD > 1.3, this can all be -shared.
