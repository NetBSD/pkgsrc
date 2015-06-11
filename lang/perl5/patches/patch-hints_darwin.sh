$NetBSD: patch-hints_darwin.sh,v 1.6 2015/06/11 13:44:23 adam Exp $

MACOSX_DEVELOPMENT_TARGET is required on version of OS X pre 10.6
See Perl bug #117433

--- hints/darwin.sh.orig	2015-05-13 20:19:29.000000000 +0000
+++ hints/darwin.sh
@@ -200,7 +200,7 @@ case "$osvers" in
    ldflags="${ldflags} -flat_namespace"
    lddlflags="${ldflags} -bundle -undefined suppress"
    ;;
-*) 
+[7-9].*) 
    # MACOSX_DEPLOYMENT_TARGET selects the minimum OS level we want to support
    # https://developer.apple.com/library/mac/documentation/DeveloperTools/Conceptual/cross_development/Configuring/configuring.html
    lddlflags="${ldflags} -bundle -undefined dynamic_lookup"
@@ -209,6 +209,9 @@ case "$osvers" in
        *) ld="env MACOSX_DEPLOYMENT_TARGET=10.3 ${ld}" ;;
    esac
    ;;
+*)
+   lddlflags="${ldflags} -bundle -undefined dynamic_lookup"
+   ;;
 esac
 ldlibpthname='DYLD_LIBRARY_PATH';
 
