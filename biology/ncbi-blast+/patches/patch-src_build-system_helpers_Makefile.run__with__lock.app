$NetBSD: patch-src_build-system_helpers_Makefile.run__with__lock.app,v 1.1 2018/04/27 20:28:28 bacon Exp $

# Missing RELRO for this one binary
# https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=820959

--- src/build-system/helpers/Makefile.run_with_lock.app.orig	2018-04-27 16:21:07.000000000 +0000
+++ src/build-system/helpers/Makefile.run_with_lock.app
@@ -6,9 +6,9 @@ CC          = $(CC_FOR_BUILD)
 CC_WRAPPER  =
 CXX_WRAPPER =
 CPP         = $(CPP_FOR_BUILD)
-CFLAGS      = $(CFLAGS_FOR_BUILD)
-CPPFLAGS    = $(CPPFLAGS_FOR_BUILD)
-LDFLAGS     = $(LDFLAGS_FOR_BUILD)
+CFLAGS      = $(CFLAGS_FOR_BUILD) -Wl,-z,relro,-z,now
+CPPFLAGS    = $(CPPFLAGS_FOR_BUILD) -Wl,-z,relro,-z,now
+LDFLAGS     = $(LDFLAGS_FOR_BUILD) -Wl,-z,relro,-z,now
 LIBS        = $(C_LIBS)
 LINK        = $(CC)
 LINK_WRAPPER =
