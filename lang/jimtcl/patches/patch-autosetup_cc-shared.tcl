$NetBSD: patch-autosetup_cc-shared.tcl,v 1.1 2021/12/07 17:51:21 jperkin Exp $

Fix install_name on Darwin.

--- autosetup/cc-shared.tcl.orig	2021-11-27 23:06:54.000000000 +0000
+++ autosetup/cc-shared.tcl
@@ -48,7 +48,7 @@ switch -glob -- [get-define host] {
 		define SH_LINKFLAGS ""
 		define SH_SOEXT .dylib
 		define SH_SOEXTVER .%s.dylib
-		define SH_SOPREFIX -Wl,-install_name,
+		define SH_SOPREFIX -Wl,-install_name,$prefix/lib/
 		define SH_SOFULLPATH
 		define LD_LIBRARY_PATH DYLD_LIBRARY_PATH
 		define STRIPLIBFLAGS -x
