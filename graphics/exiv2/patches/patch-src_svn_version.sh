$NetBSD: patch-src_svn_version.sh,v 1.2 2018/02/01 16:45:57 he Exp $

Replace an unneeded dependency on bash; do not use == with test(1)

--- src/svn_version.sh.orig	2016-08-31 18:09:37.000000000 +0000
+++ src/svn_version.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 ##
 # update svn_version_h when revision changes
@@ -11,7 +11,7 @@ s=$?
 ##
 # from Jenkins, svn is almost always a disaster because
 # Jenkins SVN Plugin is 1.7 and the build machine is normally at least 1.8
-if [ "$s" == "0" ]; then
+if [ "$s" = "0" ]; then
 	svn_version=$(svn info .. | grep '^Last Changed Rev' | cut -f 2 -d':' | tr -d ' ')
     if [ -z "$svn_version"   ]; then svn_version=0 ; fi
 else
