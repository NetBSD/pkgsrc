$NetBSD: patch-src_svn_version.sh,v 1.1.2.2 2015/10/06 17:44:21 spz Exp $

Replace an unneeded dependency on bash; do not use == with test(1)

--- src/svn_version.sh.orig	2015-10-02 05:32:33.000000000 +0200
+++ src/svn_version.sh	2015-10-02 05:32:19.000000000 +0200
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 ## 
 # update svn_version_h when revision changes
@@ -11,7 +11,7 @@
 ##
 # from Jenkins, svn is almost always a disaster because
 # Jenkins SVN Plugin is 1.7 and the build machine is normally at least 1.8
-if [ "$s" == "0" ]; then
+if [ "$s" = "0" ]; then
 	svn_version=$(svn info .. | grep ^Revision | cut -f 2 -d' ')
     if [ -z "$svn_version"   ]; then svn_version=0 ; fi
 else
