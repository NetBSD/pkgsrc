$NetBSD: patch-gcc_config_nvptx_gen-opt.sh,v 1.1 2023/03/10 22:07:24 ryoon Exp $

* Improve POSIX shell portability.

--- gcc/config/nvptx/gen-opt.sh.orig	2022-08-19 08:09:52.680663752 +0000
+++ gcc/config/nvptx/gen-opt.sh
@@ -56,7 +56,7 @@ EnumValue
 Enum(ptx_isa) String(sm_$sm) Value(PTX_ISA_SM$sm)
 EOF
 
-    if [ "$sm" == "$last" ]; then
+    if [ "$sm" = "$last" ]; then
 	# Don't end with trailing empty line.
 	continue
     fi
