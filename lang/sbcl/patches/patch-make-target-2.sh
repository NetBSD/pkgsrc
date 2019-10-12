$NetBSD: patch-make-target-2.sh,v 1.1 2019/10/12 09:47:40 he Exp $

Do not explicitly turn on job control, it will stall a bakcground job
with SIGTTIN.

--- make-target-2.sh.orig	2019-09-28 09:49:01.000000000 +0000
+++ make-target-2.sh
@@ -1,5 +1,5 @@
 #!/bin/sh
-set -em
+set -e
 
 # --load argument skips compilation.
 #
