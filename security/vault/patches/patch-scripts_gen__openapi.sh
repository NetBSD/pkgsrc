$NetBSD: patch-scripts_gen__openapi.sh,v 1.1 2019/10/23 15:00:05 he Exp $

Fix shell portability problem.

--- scripts/gen_openapi.sh.orig	2019-09-09 21:08:25.000000000 +0000
+++ scripts/gen_openapi.sh
@@ -72,7 +72,7 @@ then
 fi
 
 # Output OpenAPI, optionally formatted
-if [ "$1" == "-p" ]; then
+if [ "$1" = "-p" ]; then
   curl -H "X-Vault-Token: root" "http://127.0.0.1:8200/v1/sys/internal/specs/openapi" | jq > openapi.json
 else
   curl -H "X-Vault-Token: root" "http://127.0.0.1:8200/v1/sys/internal/specs/openapi" > openapi.json
