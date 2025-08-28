$NetBSD: patch-scripts_install-include-headers.sh,v 1.1 2025/08/28 01:27:25 gutteridge Exp $

Don't use "-v" with cp and rm, some platforms like SunOS don't
support these flags.

--- scripts/install-include-headers.sh.orig	2025-08-27 23:12:09.421796184 +0000
+++ scripts/install-include-headers.sh
@@ -16,8 +16,8 @@ if [[ -z "${SYSROOT_INC}" || -z "${TARGE
     exit 1
 fi
 # The commands are available for override to allow dry runs.
-CP="${CP:-cp -v}"
-RM="${RM:-rm -v}"
+CP="${CP:-cp}"
+RM="${RM:-rm}"
 MKDIR="${MKDIR:-mkdir}"
 SED="${SED:-sed}"
 
