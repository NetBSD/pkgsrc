$NetBSD: patch-pkgs_sqlite3.8.0_tclconfig_tcl.m4,v 1.1 2014/02/05 12:50:51 obache Exp $

--- pkgs/sqlite3.8.0/tclconfig/tcl.m4.orig	2013-09-19 20:17:11.000000000 +0000
+++ pkgs/sqlite3.8.0/tclconfig/tcl.m4
@@ -1627,26 +1627,26 @@ dnl AC_CHECK_TOOL(AR, ar)
 		;;
 	    esac
 	    ;;
-	FreeBSD-*)
+	FreeBSD-*|DragonFly-*)
 	    # This configuration from FreeBSD Ports.
 	    SHLIB_CFLAGS="-fPIC"
 	    SHLIB_LD="${CC} -shared"
-	    TCL_SHLIB_LD_EXTRAS="-soname \$[@]"
+	    TCL_SHLIB_LD_EXTRAS="-Wl,-soname \$[@]"
 	    SHLIB_SUFFIX=".so"
 	    LDFLAGS=""
 	    AS_IF([test $doRpath = yes], [
 		CC_SEARCH_FLAGS='-Wl,-rpath,${LIB_RUNTIME_DIR}'
-		LD_SEARCH_FLAGS='-rpath ${LIB_RUNTIME_DIR}'])
+		LD_SEARCH_FLAGS='-Wl,-rpath ${LIB_RUNTIME_DIR}'])
 	    AS_IF([test "${TCL_THREADS}" = "1"], [
 		# The -pthread needs to go in the LDFLAGS, not LIBS
 		LIBS=`echo $LIBS | sed s/-pthread//`
 		CFLAGS="$CFLAGS $PTHREAD_CFLAGS"
 		LDFLAGS="$LDFLAGS $PTHREAD_LIBS"])
 	    # Version numbers are dot-stripped by system policy.
-	    TCL_TRIM_DOTS=`echo ${VERSION} | tr -d .`
-	    UNSHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}.a'
-	    SHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}\$\{DBGX\}.so.1'
-	    TCL_LIB_VERSIONS_OK=nodots
+#	    TCL_TRIM_DOTS=`echo ${VERSION} | tr -d .`
+#	    UNSHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}.a'
+#	    SHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}\$\{DBGX\}.so.1'
+#	    TCL_LIB_VERSIONS_OK=nodots
 	    ;;
 	Darwin-*)
 	    CFLAGS_OPTIMIZE="-Os"
@@ -1967,7 +1967,7 @@ dnl # preprocessing tests use only CPPFL
 	    BSD/OS*) ;;
 	    CYGWIN_*) ;;
 	    IRIX*) ;;
-	    NetBSD-*|FreeBSD-*|OpenBSD-*) ;;
+	    NetBSD-*|FreeBSD-*|OpenBSD-*|DragonFly-*) ;;
 	    Darwin-*) ;;
 	    SCO_SV-3.2*) ;;
 	    windows) ;;
