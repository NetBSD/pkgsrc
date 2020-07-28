$NetBSD: patch-core_src_filed_accurate__lmdb.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	avoid uninitialized member crash.
	lmdb not verified to be working correctly though.

--- core/src/filed/accurate_lmdb.cc.orig	2020-07-17 12:18:09.949358135 +0000
+++ core/src/filed/accurate_lmdb.cc
@@ -45,6 +45,7 @@ static int debuglevel = 100;
 BareosAccurateFilelistLmdb::BareosAccurateFilelistLmdb(JobControlRecord* jcr,
                                                        uint32_t number_of_files)
 {
+  jcr_ = jcr;
   filenr_ = 0;
   pay_load_ = GetPoolMemory(PM_MESSAGE);
   lmdb_name_ = GetPoolMemory(PM_FNAME);
