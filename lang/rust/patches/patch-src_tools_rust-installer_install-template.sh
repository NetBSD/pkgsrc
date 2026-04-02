$NetBSD: patch-src_tools_rust-installer_install-template.sh,v 1.15 2026/04/02 19:06:34 wiz Exp $

No logging to 'install.log'.
Do not create 'uninstall.sh'.
Do not make file backups (filename.old), so these will not end up in the final package.

Rewrite to not use a whole lot of subprocesses just for doing
pattern matching and substitution in the install phase using "grep"
and "sed" when shell builtin "case" and "omit shortest match" ops
should do just fine.

--- src/tools/rust-installer/install-template.sh.orig	2023-12-21 16:55:28.000000000 +0000
+++ src/tools/rust-installer/install-template.sh
@@ -6,20 +6,12 @@ set -u
 init_logging() {
     local _abs_libdir="$1"
     local _logfile="$_abs_libdir/$TEMPLATE_REL_MANIFEST_DIR/install.log"
-    rm -f "$_logfile"
-    need_ok "failed to remove old installation log"
-    touch "$_logfile"
-    need_ok "failed to create installation log"
     LOGFILE="$_logfile"
 }
 
 log_line() {
     local _line="$1"
 
-    if [ -n "${LOGFILE-}" -a -e "${LOGFILE-}" ]; then
-    echo "$_line" >> "$LOGFILE"
-    # Ignore errors, which may happen e.g. after the manifest dir is deleted
-    fi
 }
 
 msg() {
@@ -433,8 +425,8 @@ uninstall_components() {
             local _directive
             while read _directive; do
 
-            local _command=`echo $_directive | cut -f1 -d:`
-            local _file=`echo $_directive | cut -f2 -d:`
+            local _command="${_directive%%:*}"
+            local _file="${_directive#*:}"
 
             # Sanity checks
             if [ ! -n "$_command" ]; then critical_err "malformed installation directive"; fi
@@ -541,8 +533,8 @@ install_components() {
     local _directive
     while read _directive; do
 
-        local _command=`echo $_directive | cut -f1 -d:`
-        local _file=`echo $_directive | cut -f2 -d:`
+        local _command="${_directive%%:*}"
+        local _file="${_directive#*:}"
 
         # Sanity checks
         if [ ! -n "$_command" ]; then critical_err "malformed installation directive"; fi
@@ -628,7 +620,6 @@ install_components() {
 
             verbose_msg "copying directory $_file_install_path"
 
-            maybe_backup_path "$_file_install_path"
 
             run cp -R "$_src_dir/$_component/$_file" "$_file_install_path"
             critical_need_ok "failed to copy directory"
@@ -977,7 +968,6 @@ write_to_file "$TEMPLATE_RUST_INSTALLER_
 critical_need_ok "failed to write installer version"
 
 # Install the uninstaller
-install_uninstaller "$src_dir" "$src_basename" "$abs_libdir"
 
 # Install each component
 install_components "$src_dir" "$abs_libdir" "$dest_prefix" "$components"
