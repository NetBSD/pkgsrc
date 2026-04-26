$NetBSD: patch-client_run.sh,v 1.1 2026/04/26 14:48:56 vins Exp $

This script is a hack to allow the `cd_create_profile' and 
`cd_idt8' executables to access their required shared libraries during
the build, as meson's RPATH gets otherwise overridden.

--- client/run.sh.orig	2026-04-26 14:18:45.688746449 +0000
+++ client/run.sh
@@ -0,0 +1,15 @@
+#!@SH@
+
+libdir="$1"
+executable="$2"
+
+if [ -z "$LD_LIBRARY_PATH" ]; then
+    LD_LIBRARY_PATH="$libdir"
+else
+    LD_LIBRARY_PATH="$libdir:$LD_LIBRARY_PATH"
+fi
+
+export LD_LIBRARY_PATH
+shift 2
+
+exec "$executable" "$@"
