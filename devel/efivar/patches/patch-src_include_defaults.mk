$NetBSD: patch-src_include_defaults.mk,v 1.1 2024/08/20 15:29:32 bsiegert Exp $

ld produces this warning:

    warning: guids.lds contains output sections; did you forget -T?

It's harmless and is meant to make user notice lack of -T, but it's not needed
here. Not clear how to suppress the warning, so removing --fatal-warnings as it
causes the build to fail.

--- src/include/defaults.mk.orig	2022-09-30 15:17:36.405877661 +0000
+++ src/include/defaults.mk
@@ -56,7 +56,6 @@ override LDFLAGS = $(CFLAGS) -L. $(_LDFL
 		   -Wl,-z,now \
 		   -Wl,-z,muldefs \
 		   -Wl,-z,relro \
-		   -Wl,--fatal-warnings \
 		   $(call family,LDFLAGS) $(call family,CCLDFLAGS) \
 		   $(call pkg-config-ccldflags)
 override CCLDFLAGS = $(LDFLAGS)
