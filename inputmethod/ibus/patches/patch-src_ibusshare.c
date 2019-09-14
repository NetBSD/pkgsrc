$NetBSD: patch-src_ibusshare.c,v 1.1 2019/09/14 04:26:39 tsutsui Exp $

- pull upstream fix
  Save address file in XDG_RUNTIME_DIR
  https://github.com/ibus/ibus/pull/2128

--- src/ibusshare.c.orig	2019-08-23 11:08:34.000000000 +0000
+++ src/ibusshare.c
@@ -142,7 +142,7 @@ ibus_get_socket_path (void)
                              ibus_get_local_machine_id (),
                              hostname,
                              displaynumber);
-        path = g_build_filename (g_get_user_config_dir (),
+        path = g_build_filename (g_get_user_runtime_dir (),
                                  "ibus",
                                  "bus",
                                  p,
