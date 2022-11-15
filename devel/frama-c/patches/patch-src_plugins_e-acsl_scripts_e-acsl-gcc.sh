$NetBSD: patch-src_plugins_e-acsl_scripts_e-acsl-gcc.sh,v 1.1 2022/11/15 13:02:42 wiz Exp $

Fix unportable test(1) operator.

--- src/plugins/e-acsl/scripts/e-acsl-gcc.sh.orig	2022-06-21 00:00:00.000000000 +0000
+++ src/plugins/e-acsl/scripts/e-acsl-gcc.sh
@@ -759,7 +759,7 @@ The size is given in MB.
 $zone_help_msg"
             ;;
           esac
-        elif [ "${#size_arr[@]}" -eq "1" ] && [ "${size_arr[0]}" == "help" ]; then
+        elif [ "${#size_arr[@]}" -eq "1" ] && [ "${size_arr[0]}" = "help" ]; then
           printf "e-acsl-gcc.sh - $zone_help_msg"
           exit 1
         else
