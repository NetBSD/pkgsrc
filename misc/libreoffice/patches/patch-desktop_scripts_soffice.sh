$NetBSD: patch-desktop_scripts_soffice.sh,v 1.5 2019/06/27 13:48:11 ryoon Exp $

1. chunk: Recent Firefox use newer version of NSS database format, cert9.db
   Use LibreOffice own cert8.db (older format).

other chunks: javaPathHelper is OpenBSD-specific
https://cgit.freedesktop.org/libreoffice/core/commit/?id=8db53bfd74e48f60e3002b2ae5f7f13c9387725a

--- desktop/scripts/soffice.sh.orig	2019-01-23 19:35:25.000000000 +0000
+++ desktop/scripts/soffice.sh
@@ -17,6 +17,10 @@
 #   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 #
 
+# Do not depend on Mozilla profiles
+MOZILLA_CERTIFICATE_FOLDER=${HOME}/.config/libreoffice
+export MOZILLA_CERTIFICATE_FOLDER
+
 # use POSIX locale for well-defined tool output
 LO_SAVE_LC_ALL="$LC_ALL"
 LC_ALL=C
@@ -156,6 +160,11 @@ NetBSD|DragonFly)
     LD_LIBRARY_PATH="$sd_prog${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
     export LD_LIBRARY_PATH
     ;;
+NetBSD|DragonFly)
+# this is a temporary hack until we can live with the default search paths
+    LD_LIBRARY_PATH="$sd_prog${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
+    export LD_LIBRARY_PATH
+    ;;
 AIX)
     LIBPATH="$sd_prog${LIBPATH:+:$LIBPATH}"
     export LIBPATH
