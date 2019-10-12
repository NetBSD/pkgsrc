$NetBSD: patch-make-genesis-2.sh,v 1.1 2019/10/12 09:47:40 he Exp $

Do not explicitly turn on job control, it will stall a bakcground job
with SIGTTIN.

--- make-genesis-2.sh.orig	2019-09-28 09:49:01.000000000 +0000
+++ make-genesis-2.sh
@@ -1,5 +1,5 @@
 #!/bin/sh
-set -em
+set -e
 
 # This is a script to be run as part of make.sh. The only time you'd
 # want to run it by itself is if you're trying to cross-compile the
