$NetBSD: patch-install.sh,v 1.1 2024/10/14 13:55:52 schmonz Exp $

Check string equality more portably (upstream commit f456bc7).

--- install.sh.orig	2024-10-14 13:42:57.310286711 +0000
+++ install.sh
@@ -175,7 +175,7 @@ check_say() {
 
 check_installation_path() {
   location="$(command -v mob)"
-  if [ "$(determine_os)" == "windows" ]; then
+  if [ "$(determine_os)" = "windows" ]; then
     location=$(echo $location | sed -E 's|^/([a-zA-Z])|\U\1:|')
   fi
   if [ "$location" != "$target/mob" ] && [ "$location" != "" ]; then
