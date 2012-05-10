$NetBSD: patch-config_StdGNU.mk,v 1.1 2012/05/10 16:07:36 abs Exp $

Allow XEN_CONFIG_DIR to be overriden in the environment

--- ../config/StdGNU.mk.orig	2012-05-10 15:51:14.000000000 +0000
+++ ../config/StdGNU.mk
@@ -53,7 +53,7 @@ endif
 
 SYSCONFIG_DIR = $(CONFIG_DIR)/$(CONFIG_LEAF_DIR)
 
-XEN_CONFIG_DIR = $(CONFIG_DIR)/xen
+XEN_CONFIG_DIR ?= $(CONFIG_DIR)/xen
 XEN_SCRIPT_DIR = $(XEN_CONFIG_DIR)/scripts
 
 SOCKET_LIBS =
