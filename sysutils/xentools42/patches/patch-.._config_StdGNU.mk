$NetBSD: patch-.._config_StdGNU.mk,v 1.1 2013/05/15 06:58:50 jnemeth Exp $

Allow XEN_CONFIG_DIR to be overriden in the environment

--- ../config/StdGNU.mk.orig	2013-04-23 16:42:55.000000000 +0000
+++ ../config/StdGNU.mk
@@ -51,13 +51,13 @@ XEN_PAGING_DIR = /var/lib/xen/xenpaging
 else
 CONFIG_DIR = $(PREFIX)/etc
 XEN_LOCK_DIR = $(PREFIX)/var/lock
-XEN_RUN_DIR = $(PREFIX)/var/run/xen
-XEN_PAGING_DIR = $(PREFIX)/var/lib/xen/xenpaging
+XEN_RUN_DIR = $(VARBASE)/run/xen
+XEN_PAGING_DIR = $(VARBASE)/lib/xen/xenpaging
 endif
 
 SYSCONFIG_DIR = $(CONFIG_DIR)/$(CONFIG_LEAF_DIR)
 
-XEN_CONFIG_DIR = $(CONFIG_DIR)/xen
+XEN_CONFIG_DIR ?= $(CONFIG_DIR)/xen
 XEN_SCRIPT_DIR = $(XEN_CONFIG_DIR)/scripts
 
 SOCKET_LIBS =
