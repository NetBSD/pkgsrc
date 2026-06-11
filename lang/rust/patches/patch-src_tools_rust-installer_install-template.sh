$NetBSD: patch-src_tools_rust-installer_install-template.sh,v 1.16 2026/06/11 07:00:57 wiz Exp $

No logging to 'install.log'.
Do not create 'uninstall.sh'.
Do not make file backups (filename.old), so these will not end up in the final package.

--- src/tools/rust-installer/install-template.sh.orig	2026-05-29 09:40:07.274418028 +0000
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
@@ -628,8 +620,6 @@ install_components() {
 
             verbose_msg "copying directory $_file_install_path"
 
-            maybe_backup_path "$_file_install_path"
-
             run cp -R "$_src_dir/$_component/$_file" "$_file_install_path"
             critical_need_ok "failed to copy directory"
 
@@ -976,9 +966,6 @@ write_to_file "$TEMPLATE_RUST_INSTALLER_
 
 critical_need_ok "failed to write installer version"
 
-# Install the uninstaller
-install_uninstaller "$src_dir" "$src_basename" "$abs_libdir"
-
 # Install each component
 install_components "$src_dir" "$abs_libdir" "$dest_prefix" "$components"
 
