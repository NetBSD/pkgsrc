$NetBSD: patch-make_template_main.mk,v 1.2 2019/05/06 17:40:16 nia Exp $

bmake: exec(ginstall) failed (No such file or directory)

--- make/template/main.mk.orig	2019-05-03 13:07:32.000000000 +0000
+++ make/template/main.mk
@@ -46,7 +46,7 @@ LOGPATH = "$(DESTDIR)@LOG_DIR@"
 DATPATH = "$(DESTDIR)@DATA_DIR@"
 BINPATH = "$(DESTDIR)@BINARY_DIR@"
 SCRPATH = "$(DESTDIR)@SCRIPT_DIR@"
-INSTALL = install
+INSTALL = $(BSD_INSTALL)
 INSTMODE_DIR = 0750
 INSTMODE_BIN = 0750
 INSTMODE_LIB = 0640
@@ -73,7 +73,6 @@ ifeq ($(SYSTEM), gnu)
 endif
 ifeq ($(SYSTEM), solaris)
   LDLIBS += -lsocket -lnsl -lrt -lresolv
-  INSTALL = ginstall
 endif
 ifeq ($(SYSTEM), darwin)
   LDLIBS += -ldl
