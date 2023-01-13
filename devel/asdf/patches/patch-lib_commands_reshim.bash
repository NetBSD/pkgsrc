$NetBSD: patch-lib_commands_reshim.bash,v 1.2 2023/01/13 22:18:11 schmonz Exp $

Use pkgsrc paths.

--- lib/commands/reshim.bash.orig	2023-01-13 14:45:18.000000000 +0000
+++ lib/commands/reshim.bash
@@ -102,9 +102,9 @@ EOF
   fi
 
   cat <<EOF >"$shim_path"
-#!/usr/bin/env bash
+#!@BASH@
 $(sort -u <"$temp_versions_path")
-exec $(asdf_dir)/bin/asdf exec "${executable_name}" "\$@" # asdf_allow: ' asdf '
+exec @PREFIX@/bin/asdf exec "${executable_name}" "\$@" # asdf_allow: ' asdf '
 EOF
 
   rm "$temp_versions_path"
