$NetBSD: patch-core_src_stored_btape.cc,v 1.2 2021/02/01 09:08:44 kardel Exp $

	add missing free*() calls

--- core/src/stored/btape.cc.orig	2020-12-16 07:46:16.000000000 +0000
+++ core/src/stored/btape.cc
@@ -327,6 +327,7 @@ int main(int margc, char* margv[])
 
 static void TerminateBtape(int status)
 {
+  FreePlugins(jcr);
   FreeJcr(jcr);
   jcr = NULL;
 
@@ -365,6 +366,8 @@ static void TerminateBtape(int status)
   }
 
   StopWatchdog();
+  FlushCryptoCache();
+  UnloadSdPlugins();
   TermMsg();
   RecentJobResultsList::Cleanup();
   CleanupJcrChain();
@@ -373,7 +376,6 @@ static void TerminateBtape(int status)
   exit(status);
 }
 
-
 btime_t total_time = 0;
 uint64_t total_size = 0;
 
