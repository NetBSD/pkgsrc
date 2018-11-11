$NetBSD: patch-test_envdir.sh,v 1.1 2018/11/11 01:59:23 schmonz Exp $

Filter out variables that trip up unset.

--- test/envdir.sh.orig	2008-04-27 20:10:53.000000000 +0000
+++ test/envdir.sh
@@ -20,7 +20,7 @@ if [ $# != 1 ]; then
     exit 1
 fi
 
-unset `env | grep -v '^PATH=' | sed 's/=.*//'`
+unset `env | grep -v '^PATH=' | grep -v '\.MAKE\.LEVEL\.ENV' | grep -v 'PKG_BUILD_OPTIONS' | sed 's/=.*//'`
 
 for i in $1/*; do
     if [ -r $i ]; then
