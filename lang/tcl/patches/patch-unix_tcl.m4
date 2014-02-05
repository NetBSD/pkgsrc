$NetBSD: patch-unix_tcl.m4,v 1.1 2014/02/05 12:50:51 obache Exp $

--- unix/tcl.m4.orig	2013-09-19 20:17:13.000000000 +0000
+++ unix/tcl.m4
@@ -1538,7 +1538,7 @@ AC_DEFUN([SC_CONFIG_CFLAGS], [
 	    	LDFLAGS="$LDFLAGS -pthread"
 	    ])
 	    ;;
-	FreeBSD-*)
+	FreeBSD-*|DragonFly-*)
 	    # This configuration from FreeBSD Ports.
 	    SHLIB_CFLAGS="-fPIC"
 	    SHLIB_LD="${CC} -shared"
