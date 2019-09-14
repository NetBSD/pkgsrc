$NetBSD: patch-bus_global.c,v 1.1 2019/09/14 04:26:39 tsutsui Exp $

- pull upstream fix
  g_dbus_server_new_sync() is failed with address unix:tmpdir=/tmp/ibus
  https://github.com/ibus/ibus/issues/2116

--- bus/global.c.orig	2019-08-23 11:08:34.000000000 +0000
+++ bus/global.c
@@ -2,7 +2,7 @@
 /* vim:set et sts=4: */
 /* ibus - The Input Bus
  * Copyright (C) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
- * Copyright (C) 2008-2010 Red Hat, Inc.
+ * Copyright (C) 2008-2019 Red Hat, Inc.
  * Copyright (c) 2012 Google, Inc.
  *
  * This library is free software; you can redistribute it and/or
@@ -21,10 +21,12 @@
  * USA
  */
 
+#include <config.h>
+
 #include "global.h"
 
 gchar **g_argv = NULL;
-gchar *g_address = "unix:tmpdir=/tmp/ibus";
+gchar *g_address = IBUS_SOCKET_DIR;
 gchar *g_cache = "auto";
 gboolean g_mempro = FALSE;
 gboolean g_verbose = FALSE;
