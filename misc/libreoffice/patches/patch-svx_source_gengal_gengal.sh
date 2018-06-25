$NetBSD: patch-svx_source_gengal_gengal.sh,v 1.1 2018/06/25 13:34:48 ryoon Exp $

javaPathHelper is OpenBSD-specific

--- svx/source/gengal/gengal.sh.orig	2018-05-04 13:30:05.000000000 +0000
+++ svx/source/gengal/gengal.sh
@@ -35,7 +35,7 @@ cd "$sd_cwd"
 
 # this is a temporary hack until we can live with the default search paths
 case "$(uname -s)" in
-NetBSD|OpenBSD|FreeBSD|DragonFly)
+OpenBSD)
     LD_LIBRARY_PATH=$sd_prog${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
     JAVA_HOME=$(javaPathHelper -h libreoffice-java 2> /dev/null)
     export LD_LIBRARY_PATH
@@ -43,6 +43,10 @@ NetBSD|OpenBSD|FreeBSD|DragonFly)
         export JAVA_HOME
     fi
     ;;
+NetBSD|FreeBSD|DragonFly)
+    LD_LIBRARY_PATH=$sd_prog${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
+    export LD_LIBRARY_PATH
+    ;;
 AIX)
     LIBPATH=$sd_prog${LIBPATH:+:${LIBPATH}}
     export LIBPATH
