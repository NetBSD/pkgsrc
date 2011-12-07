$NetBSD: patch-.._patch-Config.mk,v 1.1 2011/12/07 15:22:28 joerg Exp $

--- ../Config.mk.orig	2011-12-07 10:40:48.000000000 +0000
+++ ../Config.mk
@@ -70,7 +70,7 @@ CFLAGS += -Wall -Wstrict-prototypes
 
 # -Wunused-value makes GCC 4.x too aggressive for my taste: ignoring the
 # result of any casted expression causes a warning.
-CFLAGS += -Wno-unused-value
+CFLAGS += -Wno-unused-value -Wno-switch
 
 HOSTCFLAGS += $(call cc-option,$(HOSTCC),-Wdeclaration-after-statement,)
 CFLAGS     += $(call cc-option,$(CC),-Wdeclaration-after-statement,)
