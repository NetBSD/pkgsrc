$NetBSD: patch-hints_darwin.sh,v 1.4 2013/07/18 07:21:02 adam Exp $

Don't set MACOSX_DEPLOYMENT_TARGET.

--- hints/darwin.sh.orig	2013-05-07 14:45:09.000000000 +0000
+++ hints/darwin.sh
@@ -183,10 +183,6 @@ case "$osvers" in
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
