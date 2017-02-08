$NetBSD: patch-Rsync.pm,v 1.1 2017/02/08 10:35:21 hauke Exp $

Default to an absolute path for rsync. We explicitly depend on it,
and it may not be first in PATH, or not at all.

--- Rsync.pm.orig	2016-03-09 20:36:13.000000000 +0000
+++ Rsync.pm
@@ -241,7 +241,7 @@ sub new {
       },
       _perlopts => {
          # the path name to the rsync binary (default is to use $PATH)
-         'path-to-rsync' => 'rsync',
+         'path-to-rsync' => '@PREFIX@/bin/rsync',
          # hostname of source, used if 'source' is an array reference
          'srchost' => '',
          # double-quote source and/or destination paths
