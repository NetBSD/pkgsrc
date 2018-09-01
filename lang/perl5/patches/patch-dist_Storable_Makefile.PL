$NetBSD: patch-dist_Storable_Makefile.PL,v 1.1 2018/09/01 08:03:02 schmonz Exp $

Fix Storable build on OS X where DYLD_LIBRARY_PATH is no longer
inherited by child processes.

--- dist/Storable/Makefile.PL.orig	2018-05-21 12:29:23.000000000 +0000
+++ dist/Storable/Makefile.PL
@@ -95,7 +95,7 @@ sub depend {
     "
 $limit_pm : stacksize \$(INST_$linktype)$extra_deps
 	\$(MKPATH) \$(INST_LIB)
-	\$(FULLPERLRUNINST) stacksize $options
+	\$(LDLIBPTH) \$(FULLPERLRUNINST) stacksize $options
 
 release : dist
 	git tag \$(VERSION)
