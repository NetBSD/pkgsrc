$NetBSD: patch-xen_Rules.mk,v 1.1 2020/05/26 11:12:11 bouyer Exp $

--- xen/Rules.mk.orig	2018-04-23 14:50:02.000000000 +0200
+++ xen/Rules.mk	2018-04-23 14:50:32.000000000 +0200
@@ -1,4 +1,7 @@
 
+#reset cflags. Why is it needed in pkgsrc ?
+CFLAGS=
+
 -include $(BASEDIR)/include/config/auto.conf
 
 include $(XEN_ROOT)/Config.mk
