$NetBSD: patch-speech__tools_config_modules_editline.mak,v 1.1.2.2 2017/05/01 08:49:56 bsiegert Exp $

Ensure the chosen termcap library can be found.

--- speech_tools/config/modules/editline.mak.orig	2002-07-22 22:57:53.000000000 +0000
+++ speech_tools/config/modules/editline.mak
@@ -43,7 +43,7 @@ INCLUDE_EDITLINE=1
 MOD_DESC_EDITLINE=Use editline for command line editing and history
 
 IO_DEFINES   += -DSUPPORT_EDITLINE $(MODULE_EDITLINE_OPTIONS:%=-DEDITLINE_%)
-MODULE_LIBS  += $(TERMCAPLIB)
+MODULE_LIBS  += ${BUILDLINK_LDFLAGS} $(TERMCAPLIB)
 
 ifeq ($(DIRNAME),siod)
     CSRCS := $(CSRCS) el_complete.c editline.c el_sys_unix.c
