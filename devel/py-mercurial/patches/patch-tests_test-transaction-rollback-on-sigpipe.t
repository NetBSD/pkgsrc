$NetBSD: patch-tests_test-transaction-rollback-on-sigpipe.t,v 1.1 2020/11/09 14:42:46 wiz Exp $

https://bz.mercurial-scm.org/show_bug.cgi?id=6429

--- tests/test-transaction-rollback-on-sigpipe.t.orig	2020-11-02 19:26:18.000000000 +0000
+++ tests/test-transaction-rollback-on-sigpipe.t
@@ -22,14 +22,14 @@ disconnecting.
 
   $ killable_pipe=`pwd`/killable_pipe.sh
   $ script $killable_pipe <<EOF
-  > #!/bin/bash
+  > #!/usr/bin/env bash
   > echo \$\$ >> $pidfile
   > exec cat
   > EOF
 
   $ remotecmd=`pwd`/remotecmd.sh
   $ script $remotecmd <<EOF
-  > #!/bin/bash
+  > #!/usr/bin/env bash
   > hg "\$@" 1> >($killable_pipe) 2> >($killable_pipe >&2)
   > EOF
 
@@ -38,7 +38,7 @@ disconnecting. Then exit nonzero, to for
 
   $ hook_script=`pwd`/pretxnchangegroup.sh
   $ script $hook_script <<EOF
-  > #!/bin/bash
+  > #!/usr/bin/env bash
   > for pid in \$(cat $pidfile) ; do
   >   kill \$pid
   >   while kill -0 \$pid 2>/dev/null ; do
