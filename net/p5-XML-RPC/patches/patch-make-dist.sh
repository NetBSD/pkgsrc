$NetBSD: patch-make-dist.sh,v 1.1 2017/01/24 13:39:42 mef Exp $

ERROR: [check-portability.awk] => Found test ... == ...:

--- make-dist.sh.orig	2009-01-02 05:42:33.000000000 +0900
+++ make-dist.sh	2017-01-21 21:49:15.000000000 +0900
@@ -20,7 +20,7 @@ doit make
 doit make disttest
 
 main=`grep version_from META.yml | cut -f 2 -d :`
-[ "$main" == "" ] && die "version_from is not found in META.yml"
+[ "$main" = "" ] && die "version_from is not found in META.yml"
 doit pod2text $main > README
 
 doit make dist
