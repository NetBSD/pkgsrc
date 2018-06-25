$NetBSD: patch-desktop_scripts_soffice.sh,v 1.3 2018/06/25 21:51:38 wiz Exp $

1. chunk: ?

other chunks: javaPathHelper is OpenBSD-specific
https://cgit.freedesktop.org/libreoffice/core/commit/?id=8db53bfd74e48f60e3002b2ae5f7f13c9387725a

--- desktop/scripts/soffice.sh.orig	2018-05-04 13:30:05.000000000 +0000
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
@@ -141,7 +145,7 @@ if echo "$checks" | grep -q "cc" ; then
 fi
 
 case "$(uname -s)" in
-NetBSD|OpenBSD|DragonFly)
+OpenBSD)
 # this is a temporary hack until we can live with the default search paths
     LD_LIBRARY_PATH="$sd_prog${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
     JAVA_HOME=$(javaPathHelper -h libreoffice-java 2> /dev/null)
@@ -150,6 +154,11 @@ NetBSD|OpenBSD|DragonFly)
         export JAVA_HOME
     fi
     ;;
+NetBSD|DragonFly)
+# this is a temporary hack until we can live with the default search paths
+    LD_LIBRARY_PATH="$sd_prog${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
+    export LD_LIBRARY_PATH
+    ;;
 AIX)
     LIBPATH="$sd_prog${LIBPATH:+:$LIBPATH}"
     export LIBPATH
