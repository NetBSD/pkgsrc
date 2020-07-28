$NetBSD: patch-core_src_stored_btape.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	Add missing free*() calls to keep smartalloc happy

--- core/src/stored/btape.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/stored/btape.cc
@@ -331,6 +331,7 @@ int main(int margc, char* margv[])
 
 static void TerminateBtape(int status)
 {
+  FreePlugins(jcr);
   FreeJcr(jcr);
   jcr = NULL;
 
@@ -369,6 +370,8 @@ static void TerminateBtape(int status)
   }
 
   StopWatchdog();
+  FlushCryptoCache();
+  UnloadSdPlugins();
   TermMsg();
   RecentJobResultsList::Cleanup();
   CleanupJcrChain();
@@ -377,7 +380,6 @@ static void TerminateBtape(int status)
   exit(status);
 }
 
-
 btime_t total_time = 0;
 uint64_t total_size = 0;
 
