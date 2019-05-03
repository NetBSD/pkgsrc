$NetBSD: patch-make_template_main.mk,v 1.1 2019/05/03 17:14:28 nia Exp $

bmake: exec(ginstall) failed (No such file or directory)

--- make/template/main.mk.orig	2019-05-03 13:07:32.000000000 +0000
+++ make/template/main.mk
@@ -73,7 +73,6 @@ ifeq ($(SYSTEM), gnu)
 endif
 ifeq ($(SYSTEM), solaris)
   LDLIBS += -lsocket -lnsl -lrt -lresolv
-  INSTALL = ginstall
 endif
 ifeq ($(SYSTEM), darwin)
   LDLIBS += -ldl
