$NetBSD: patch-hints_darwin.sh,v 1.5 2014/11/22 15:45:41 bsiegert Exp $

MACOSX_DEVELOPMENT_TARGET is required on version of OS X pre 10.6
See Perl bug #117433

--- hints/darwin.sh.orig	2014-09-14 11:31:02.000000000 +0000
+++ hints/darwin.sh
@@ -185,13 +185,16 @@ case "$osvers" in
    ldflags="${ldflags} -flat_namespace"
    lddlflags="${ldflags} -bundle -undefined suppress"
    ;;
-*) 
+[7-9].*)
    lddlflags="${ldflags} -bundle -undefined dynamic_lookup"
    case "$ld" in
        *MACOSX_DEVELOPMENT_TARGET*) ;;
        *) ld="env MACOSX_DEPLOYMENT_TARGET=10.3 ${ld}" ;;
    esac
    ;;
+*)
+   lddlflags="${ldflags} -bundle -undefined dynamic_lookup"
+   ;;
 esac
 ldlibpthname='DYLD_LIBRARY_PATH';
 
