$NetBSD: patch-sysupgrade.sh,v 1.3 2019/06/06 16:30:13 triaxx Exp $

* Don't reject https in sysupgrade_fetch()
* Add ARCHIVE_EXTENSION variable (Fix PR pkg/53697)

--- sysupgrade.sh.orig	2013-07-28 21:27:57.000000000 +0000
+++ sysupgrade.sh
@@ -39,7 +39,8 @@ shtk_import process
 #
 # Please remember to update sysbuild(1) if you change this list.
 SYSUPGRADE_CONFIG_VARS="AUTOCLEAN CACHEDIR DESTDIR ETCUPDATE KERNEL
-                        POSTINSTALL_AUTOFIX RELEASEDIR SETS"
+                        POSTINSTALL_AUTOFIX RELEASEDIR SETS
+                        ARCHIVE_EXTENSION"
 
 
 # Directory in which to keep downloaded release files.
@@ -66,6 +67,7 @@ sysupgrade_set_defaults() {
     shtk_config_set ETCUPDATE "yes"
     shtk_config_set KERNEL "AUTO"
     shtk_config_set SETS "AUTO"
+    shtk_config_set ARCHIVE_EXTENSION "tgz"
 }
 
 
@@ -163,18 +165,29 @@ require_cached_file() {
 # The set to be extracted must have been previously fetched into the cache
 # directory by sysupgrade_fetch command.
 #
-# \param set_name Name of the set to extract, without the .tgz extension.
+# \param set_name Name of the set to extract, without the archive extension.
 extract_set() {
     local set_name="${1}"; shift
+    local arch_ext="$(shtk_config_get ARCHIVE_EXTENSION)"
 
-    require_cached_file "${set_name}.tgz"
+    require_cached_file "${set_name}.${arch_ext}"
 
     local destdir="$(shtk_config_get_default DESTDIR "")"
-    local set_tgz="$(get_cached_file "${set_name}.tgz")"
+    local set_arch="$(get_cached_file "${set_name}.${arch_ext}")"
 
     shtk_cli_info "Extracting ${set_name} into ${destdir}/"
     [ -z "${destdir}" ] || shtk_process_run mkdir -p "${destdir}"
-    progress -zf "${set_tgz}" tar -xp -C "${destdir}/" -f -
+    case "${arch_ext}" in
+        tgz)
+            progress -zf "${set_arch}" tar -xp -C "${destdir}/" -f -
+            ;;
+        tar.xz)
+            progress -f "${set_arch}" tar -xJp -C "${destdir}/" -f -
+            ;;
+        *)
+            shtk_cli_error "Unsupported archive extension ${arch_ext}"
+            ;;
+        esac
 }
 
 
@@ -189,9 +202,10 @@ sysupgrade_fetch() {
 
     local releasedir="$(shtk_config_get RELEASEDIR)"
     local cachedir="$(shtk_config_get CACHEDIR)"
+    local arch_ext="$(shtk_config_get ARCHIVE_EXTENSION)"
     local fetch_files=
     for set_name in $(shtk_config_get SETS); do
-        fetch_files="${fetch_files} binary/sets/${set_name}.tgz"
+        fetch_files="${fetch_files} binary/sets/${set_name}.${arch_ext}"
     done
     if shtk_config_has KERNEL; then
         local kernel_name="$(shtk_config_get KERNEL)"
@@ -199,7 +213,7 @@ sysupgrade_fetch() {
     fi
 
     case "${releasedir}" in
-        ftp://*|http://*)
+        ftp://*|http://*|https://*)
             mkdir -p "${cachedir}"
 
             for relative_file in ${fetch_files}; do
@@ -320,6 +334,7 @@ sysupgrade_modules() {
 #
 # \param ... Names of the sets to extract, to override SETS.
 sysupgrade_sets() {
+    local arch_ext="$(shtk_config_get ARCHIVE_EXTENSION)"
     local sets=
     for set_name in "${@:-$(shtk_config_get SETS)}"; do
         case "${set_name}" in
@@ -334,7 +349,7 @@ sysupgrade_sets() {
     done
 
     for set_name in ${sets}; do
-        require_cached_file "${set_name}.tgz"
+        require_cached_file "${set_name}.${arch_ext}"
     done
 
     shtk_cli_info "Upgrading base system"
@@ -346,6 +361,7 @@ sysupgrade_sets() {
 
 # Runs etcupdate to install new configuration files.
 sysupgrade_etcupdate() {
+    local arch_ext="$(shtk_config_get ARCHIVE_EXTENSION)"
     [ ${#} -eq 0 ] || shtk_cli_usage_error "etcupdate does not take any" \
         "arguments"
 
@@ -366,8 +382,8 @@ sysupgrade_etcupdate() {
 
     local sflags=
     for set_name in ${sets}; do
-        require_cached_file "${set_name}.tgz"
-        sflags="${sflags} -s$(get_cached_file "${set_name}.tgz")"
+        require_cached_file "${set_name}.${arch_ext}"
+        sflags="${sflags} -s$(get_cached_file "${set_name}.${arch_ext}")"
     done
 
     shtk_cli_info "Upgrading /etc interactively"
@@ -381,6 +397,7 @@ sysupgrade_etcupdate() {
 sysupgrade_postinstall() {
     local sets=
     local sets="$(shtk_list_filter '*etc' $(shtk_config_get SETS))"
+    local arch_ext="$(shtk_config_get ARCHIVE_EXTENSION)"
     if [ -z "${sets}" ]; then
         shtk_cli_info "Skipping postinstall (no etc sets in SETS)"
         return 0
@@ -392,8 +409,8 @@ sysupgrade_postinstall() {
 
     local sflags=
     for set_name in ${sets}; do
-        require_cached_file "${set_name}.tgz"
-        sflags="${sflags} -s$(get_cached_file "${set_name}.tgz")"
+        require_cached_file "${set_name}.${arch_ext}"
+        sflags="${sflags} -s$(get_cached_file "${set_name}.${arch_ext}")"
     done
 
     shtk_cli_info "Performing postinstall checks"
