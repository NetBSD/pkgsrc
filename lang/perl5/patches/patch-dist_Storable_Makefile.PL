$NetBSD: patch-dist_Storable_Makefile.PL,v 1.2 2019/04/23 09:27:46 adam Exp $

Fix Storable build on OS X where DYLD_LIBRARY_PATH is no longer
inherited by child processes.

--- dist/Storable/Makefile.PL.orig	2019-04-02 20:36:35.000000000 +0000
+++ dist/Storable/Makefile.PL
@@ -102,7 +102,7 @@ sub depend {
     "
 $limit_pm : stacksize \$(INST_$linktype)$extra_deps
 	\$(MKPATH) \$(INST_LIB)
-	$whichperl stacksize $options
+	\$(LDLIBPTH) $whichperl stacksize $options
 
 release : dist
 	git tag \$(VERSION)
