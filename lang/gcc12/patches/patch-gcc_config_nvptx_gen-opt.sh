$NetBSD: patch-gcc_config_nvptx_gen-opt.sh,v 1.1 2022/06/16 15:43:55 adam Exp $

Portability fix.

--- gcc/config/nvptx/gen-opt.sh.orig	2022-06-15 15:52:17.000000000 +0000
+++ gcc/config/nvptx/gen-opt.sh
@@ -56,7 +56,7 @@ EnumValue
 Enum(ptx_isa) String(sm_$sm) Value(PTX_ISA_SM$sm)
 EOF
 
-    if [ "$sm" == "$last" ]; then
+    if [ "$sm" = "$last" ]; then
 	# Don't end with trailing empty line.
 	continue
     fi
