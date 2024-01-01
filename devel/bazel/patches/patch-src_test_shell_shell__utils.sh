$NetBSD: patch-src_test_shell_shell__utils.sh,v 1.1 2024/01/01 12:00:59 ryoon Exp $

--- src/test/shell/shell_utils.sh.orig	2023-11-28 16:48:06.068223021 +0000
+++ src/test/shell/shell_utils.sh
@@ -110,7 +110,7 @@ function get_real_path() {
 function md5_file() {
   if [ $# -gt 0 ]; then
     local result=""
-    if [[ ${PLATFORM} == "darwin" ]] || [[ ${PLATFORM} == "freebsd" ]] || [[ ${PLATFORM} == "openbsd" ]]; then
+    if [[ ${PLATFORM} == "darwin" ]] || [[ ${PLATFORM} == "freebsd" ]] || [[ ${PLATFORM} == "netbsd" ]] || [[ ${PLATFORM} == "openbsd" ]]; then
       result=$(md5 -q $@ || echo)
     else
       result=$(md5sum $@ | awk '{print $1}' || echo)
