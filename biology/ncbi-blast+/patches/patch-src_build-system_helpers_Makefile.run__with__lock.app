$NetBSD: patch-src_build-system_helpers_Makefile.run__with__lock.app,v 1.2 2018/05/22 21:37:29 bacon Exp $

# Missing RELRO for this one binary
# https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=820959

--- src/build-system/helpers/Makefile.run_with_lock.app.orig	2016-02-23 17:06:47.000000000 +0000
+++ src/build-system/helpers/Makefile.run_with_lock.app
@@ -6,9 +6,9 @@ CC          = $(CC_FOR_BUILD)
 CC_WRAPPER  =
 CXX_WRAPPER =
 CPP         = $(CPP_FOR_BUILD)
-CFLAGS      = $(CFLAGS_FOR_BUILD)
-CPPFLAGS    = $(CPPFLAGS_FOR_BUILD)
-LDFLAGS     = $(LDFLAGS_FOR_BUILD)
+CFLAGS      := $(CFLAGS_FOR_BUILD) $(CFLAGS)
+CPPFLAGS    := $(CPPFLAGS_FOR_BUILD) $(CPPFLAGS)
+LDFLAGS     := $(LDFLAGS_FOR_BUILD) $(LDFLAGS)
 LIBS        = $(C_LIBS)
 LINK        = $(CC)
 LINK_WRAPPER =
