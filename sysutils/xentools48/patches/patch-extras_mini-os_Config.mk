--- extras/mini-os/Config.mk.orig	2017-03-27 19:37:46.000000000 +0200
+++ extras/mini-os/Config.mk	2017-03-27 19:38:46.000000000 +0200
@@ -106,13 +106,7 @@
 # Set tools
 AS         = $(CROSS_COMPILE)as
 LD         = $(CROSS_COMPILE)ld
-ifeq ($(clang),y)
-CC         = $(CROSS_COMPILE)clang
-LD_LTO     = $(CROSS_COMPILE)llvm-ld
-else
-CC         = $(CROSS_COMPILE)gcc
-LD_LTO     = $(CROSS_COMPILE)ld
-endif
+CC         = $(TARGET_CC)
 CPP        = $(CC) -E
 AR         = $(CROSS_COMPILE)ar
 RANLIB     = $(CROSS_COMPILE)ranlib
