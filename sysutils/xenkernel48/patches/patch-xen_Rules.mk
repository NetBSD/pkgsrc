$NetBSD: patch-xen_Rules.mk,v 1.1 2017/03/30 09:15:09 bouyer Exp $

--- xen/Rules.mk.orig	2017-03-21 18:32:41.000000000 +0100
+++ xen/Rules.mk	2017-03-21 18:33:07.000000000 +0100
@@ -5,6 +5,9 @@
 #
 lto           ?= n
 
+#reset cflags. Why is it needed in pkgsrc ?
+CFLAGS=
+
 -include $(BASEDIR)/include/config/auto.conf
 
 include $(XEN_ROOT)/Config.mk
