$NetBSD: patch-src_helper_configuration.h,v 1.1 2025/04/06 10:07:06 adam Exp $

Fix build.

--- src/helper/configuration.h.orig	2025-04-06 05:55:27.179913451 +0000
+++ src/helper/configuration.h
@@ -11,6 +11,7 @@
 #ifndef OPENOCD_HELPER_CONFIGURATION_H
 #define OPENOCD_HELPER_CONFIGURATION_H
 
+#include <stdio.h>
 #include <helper/command.h>
 
 int parse_cmdline_args(struct command_context *cmd_ctx,
