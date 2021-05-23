$NetBSD: patch-scripts_mysqld__safe.sh,v 1.1 2021/05/23 15:32:47 nia Exp $

Shell portability.

--- scripts/mysqld_safe.sh.orig	2020-01-26 20:43:53.000000000 +0000
+++ scripts/mysqld_safe.sh
@@ -210,7 +210,7 @@ wsrep_pick_url() {
     nc -z "$host" $port >/dev/null && break
   done
 
-  if [ "$url" == "0" ]; then
+  if [ "$url" = "0" ]; then
     log_error "ERROR: none of the URLs in '$@' is reachable."
     return 1
   fi
