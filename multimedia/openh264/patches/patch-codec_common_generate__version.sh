$NetBSD: patch-codec_common_generate__version.sh,v 1.1 2021/11/16 14:56:36 nia Exp $

Avoid running git to determine the version.

--- codec/common/generate_version.sh.orig	2020-05-21 08:30:24.000000000 +0000
+++ codec/common/generate_version.sh
@@ -1,19 +1,7 @@
 #!/bin/bash
-git rev-list HEAD | sort > config.git-hash
 SRC_PATH=$1
-LOCALVER=`wc -l config.git-hash | awk '{print $1}'`
-if [ $LOCALVER \> 1 ] ; then
-    VER="$(git rev-list HEAD -n 1 | cut -c 1-7)"
-    if git status | grep -q "modified:" ; then
-        VER="${VER}+M"
-    fi
-    GIT_VERSION=$VER
-else
-    GIT_VERSION=
-    VER="x"
-fi
-GIT_VERSION='"'$GIT_VERSION'"'
-rm -f config.git-hash
+GIT_VERSION='"(pkgsrc)"'
+VER="x"
 
 mkdir -p codec/common/inc
 cat $SRC_PATH/codec/common/inc/version_gen.h.template | sed "s/\$FULL_VERSION/$GIT_VERSION/g" > codec/common/inc/version_gen.h.new
