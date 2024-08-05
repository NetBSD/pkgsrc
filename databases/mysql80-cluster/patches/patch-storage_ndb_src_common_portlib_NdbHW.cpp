$NetBSD: patch-storage_ndb_src_common_portlib_NdbHW.cpp,v 1.1 2024/08/05 01:24:00 jnemeth Exp $

--- storage/ndb/src/common/portlib/NdbHW.cpp.orig	2024-03-27 19:25:51.000000000 +0000
+++ storage/ndb/src/common/portlib/NdbHW.cpp
@@ -942,7 +942,7 @@ Uint32 Ndb_getCPUL3CacheId(Uint32 cpu_id
 }
 
 #if defined(HAVE_SOLARIS_AFFINITY) || defined(HAVE_LINUX_SCHEDULING) || \
-    defined(HAVE_CPUSET_SETAFFINITY)
+    defined(HAVE_CPUSET_SETAFFINITY) || defined(__NetBSD__)
 static void check_cpu_online(struct ndb_hwinfo *hwinfo) {
   for (Uint32 i = 0; i < hwinfo->cpu_cnt_max; i++) {
     if (!NdbThread_IsCPUAvailable(i)) {
@@ -1817,7 +1817,7 @@ static int Ndb_ReloadHWInfo(struct ndb_h
   return get_meminfo(hwinfo);
 }
 
-#elif defined HAVE_SOLARIS_AFFINITY
+#elif defined HAVE_SOLARIS_AFFINITY || defined(__NetBSD__)
 /* Solaris HW Information */
 
 /**
