$NetBSD: patch-src_tools_rust-installer_install-template.sh,v 1.11 2023/10/25 05:50:43 pin Exp $

No logging to 'install.log'.
Do not create 'uninstall.sh'.

Rewrite to not use a whole lot of subprocesses just for doing
pattern matching and substitution in the install phase using "grep"
and "sed" when shell builtin "case" and "omit shortest match" ops
should do just fine.

--- src/tools/rust-installer/install-template.sh.orig	2021-05-09 02:52:58.000000000 +0000
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
+            local _command=${_directive%%:*}
+            local _file=${_directive#*:}
 
             # Sanity checks
             if [ ! -n "$_command" ]; then critical_err "malformed installation directive"; fi
@@ -541,8 +533,8 @@ install_components() {
     local _directive
     while read _directive; do
 
-        local _command=`echo $_directive | cut -f1 -d:`
-        local _file=`echo $_directive | cut -f2 -d:`
+        local _command=${_directive%%:*}
+        local _file=${_directive#*:}
 
         # Sanity checks
         if [ ! -n "$_command" ]; then critical_err "malformed installation directive"; fi
@@ -551,36 +543,24 @@ install_components() {
         # Decide the destination of the file
         local _file_install_path="$_dest_prefix/$_file"
 
-        if echo "$_file" | grep "^etc/" > /dev/null
-        then
-        local _f="$(echo "$_file" | sed 's/^etc\///')"
-        _file_install_path="$CFG_SYSCONFDIR/$_f"
-        fi
-
-        if echo "$_file" | grep "^bin/" > /dev/null
-        then
-        local _f="$(echo "$_file" | sed 's/^bin\///')"
-        _file_install_path="$CFG_BINDIR/$_f"
-        fi
-
-        if echo "$_file" | grep "^lib/" > /dev/null
-        then
-        local _f="$(echo "$_file" | sed 's/^lib\///')"
-        _file_install_path="$CFG_LIBDIR/$_f"
-        fi
-
-        if echo "$_file" | grep "^share" > /dev/null
-        then
-        local _f="$(echo "$_file" | sed 's/^share\///')"
-        _file_install_path="$CFG_DATADIR/$_f"
-        fi
-
-        if echo "$_file" | grep "^share/man/" > /dev/null
-        then
-        local _f="$(echo "$_file" | sed 's/^share\/man\///')"
-        _file_install_path="$CFG_MANDIR/$_f"
-        fi
-
+        case "$_file" in
+            etc/*)
+                local _f=${_file#"etc/"}
+                _file_install_path="$CFG_DESTDIR_PREFIX/share/doc/cargo/$_f"
+                ;;
+            bin/*)
+                local _f=${_file#"bin/"}
+                _file_install_path="$CFG_BINDIR/$_f"
+                ;;
+            lib/*)
+                local _f=${_file#"lib/"}
+                _file_install_path="$CFG_LIBDIR/$_f"
+                ;;
+            share/man/*)
+                local _f=${_file#"share/man/"}
+                _file_install_path="$CFG_MANDIR/$_f"
+                ;;
+            share/doc/*)
             # HACK: Try to support overriding --docdir.  Paths with the form
             # "share/doc/$product/" can be redirected to a single --docdir
             # path. If the following detects that --docdir has been specified
@@ -591,14 +571,17 @@ install_components() {
             # contents of those directories are _not_ disjoint. Since this feature
             # is almost entirely to support 'make install' anyway I don't expect
             # this problem to be a big deal in practice.
-            if [ "$CFG_DOCDIR" != "<default>" ]
-            then
-            if echo "$_file" | grep "^share/doc/" > /dev/null
-            then
-            local _f="$(echo "$_file" | sed 's/^share\/doc\/[^/]*\///')"
-            _file_install_path="$CFG_DOCDIR/$_f"
-            fi
-            fi
+                if [ "$CFG_DOCDIR" != "<default>" ]; then
+                    local _f=${_file#"share/doc/"*/}
+                    _file_install_path="$CFG_DOCDIR/$_f"
+                fi
+                ;;
+            share/*)
+                local _f=${_file#"share/"}
+                _file_install_path="$CFG_DATADIR/$_f"
+                ;;
+        esac
+
 
         # Make sure there's a directory for it
         make_dir_recursive "$(dirname "$_file_install_path")"
@@ -617,14 +600,16 @@ install_components() {
 
             maybe_backup_path "$_file_install_path"
 
-            if echo "$_file" | grep "^bin/" > /dev/null || test -x "$_src_dir/$_component/$_file"
-            then
-            run cp "$_src_dir/$_component/$_file" "$_file_install_path"
-            run chmod 755 "$_file_install_path"
-            else
+            local mode=644
+            if test -x "$_src_dir/$_component/$_file"; then
+                mode=755
+            fi
+            case "$_file" in
+                bin/*) mode=755
+                       ;;
+            esac
             run cp "$_src_dir/$_component/$_file" "$_file_install_path"
-            run chmod 644 "$_file_install_path"
-            fi
+            run chmod $mode "$_file_install_path"
             critical_need_ok "file creation failed"
 
             # Update the manifest
@@ -986,7 +971,6 @@ write_to_file "$TEMPLATE_RUST_INSTALLER_
 critical_need_ok "failed to write installer version"
 
 # Install the uninstaller
-install_uninstaller "$src_dir" "$src_basename" "$abs_libdir"
 
 # Install each component
 install_components "$src_dir" "$abs_libdir" "$dest_prefix" "$components"
