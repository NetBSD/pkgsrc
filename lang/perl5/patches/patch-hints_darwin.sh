$NetBSD: patch-hints_darwin.sh,v 1.3 2013/07/17 20:06:05 adam Exp $

Don't set MACOSX_DEPLOYMENT_TARGET.

--- hints/darwin.sh.orig	2013-07-17 21:57:17.000000000 +0200
+++ hints/darwin.sh	2013-07-17 21:58:23.000000000 +0200
@@ -183,10 +183,6 @@
    ;;
 *) 
    lddlflags="${ldflags} -bundle -undefined dynamic_lookup"
-   case "$ld" in
-       *MACOSX_DEVELOPMENT_TARGET*) ;;
-       *) ld="env MACOSX_DEPLOYMENT_TARGET=10.3 ${ld}" ;;
-   esac
    ;;
 esac
 ldlibpthname='DYLD_LIBRARY_PATH';
