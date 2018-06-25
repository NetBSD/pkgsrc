$NetBSD: patch-desktop_scripts_unopkg.sh,v 1.2 2018/06/25 21:51:38 wiz Exp $

javaPathHelper is OpenBSD-specific
https://cgit.freedesktop.org/libreoffice/core/commit/?id=8db53bfd74e48f60e3002b2ae5f7f13c9387725a

--- desktop/scripts/unopkg.sh.orig	2018-05-04 13:30:05.000000000 +0000
+++ desktop/scripts/unopkg.sh
@@ -37,7 +37,7 @@ cd "$sd_cwd" || exit $?
 
 # this is a temporary hack until we can live with the default search paths
 case "$(uname -s)" in
-NetBSD|OpenBSD|FreeBSD|DragonFly)
+OpenBSD)
     LD_LIBRARY_PATH="$sd_prog${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}"
     JAVA_HOME=$(javaPathHelper -h libreoffice-java 2> /dev/null)
     export LD_LIBRARY_PATH
@@ -45,6 +45,10 @@ NetBSD|OpenBSD|FreeBSD|DragonFly)
         export JAVA_HOME
     fi
     ;;
+NetBSD|FreeBSD|DragonFly)
+    LD_LIBRARY_PATH="$sd_prog${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}"
+    export LD_LIBRARY_PATH
+    ;;
 AIX)
     LIBPATH="$sd_prog${LIBPATH:+:${LIBPATH}}"
     export LIBPATH
