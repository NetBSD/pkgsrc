$NetBSD: patch-lib_commands_reshim.bash,v 1.1 2022/12/27 16:11:01 schmonz Exp $

Use pkgsrc paths.

--- lib/commands/reshim.bash.orig	2022-12-14 20:53:20.000000000 +0000
+++ lib/commands/reshim.bash
@@ -97,7 +97,7 @@ write_shim_script() {
     cat <<EOF >"$shim_path"
 #!/usr/bin/env bash
 # asdf-plugin: ${plugin_name} ${version}
-exec $(asdf_dir)/bin/asdf exec "${executable_name}" "\$@" # asdf_allow: ' asdf '
+exec @PREFIX@/bin/asdf exec "${executable_name}" "\$@" # asdf_allow: ' asdf '
 EOF
   fi
 
