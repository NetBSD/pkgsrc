$NetBSD: patch-build_make_lz4defs.make,v 1.1 2026/11/09 14:20:58 wiz Exp $

Unlock install target.

--- build/make/lz4defs.make.orig	2026-11-04 00:58:16.000000000 +0000
+++ build/make/lz4defs.make
@@ -122,11 +122,7 @@
 JCC_FLAGS = $(eval JCC_FLAGS := $(JCC_PROBE))$(JCC_FLAGS)
 endif
 
-ifneq (,$(filter Linux Darwin GNU/kFreeBSD GNU OpenBSD FreeBSD NetBSD DragonFly SunOS Haiku MidnightBSD MINGW% CYGWIN% MSYS% AIX,$(shell $(UNAME))))
 POSIX_ENV = Yes
-else
-POSIX_ENV = No
-endif
 
 # Avoid symlinks when targeting Windows or building on a Windows host
 ifeq ($(WINBASED),yes)
