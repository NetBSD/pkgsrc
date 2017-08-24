$NetBSD: patch-tools_build_src_engine_build.sh,v 1.1 2017/08/24 19:31:32 adam Exp $

--- tools/build/src/engine/build.sh.orig	2017-08-19 16:49:50.000000000 +0000
+++ tools/build/src/engine/build.sh
@@ -274,6 +274,7 @@ case $BOOST_JAM_TOOLSET in
     error_exit "Unknown toolset: $BOOST_JAM_TOOLSET"
     ;;
 esac
+BOOST_JAM_CC="${BOOST_JAM_CC} ${CFLAGS} ${LDFLAGS}"
 
 echo "###"
 echo "### Using '$BOOST_JAM_TOOLSET' toolset."
