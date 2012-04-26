$NetBSD: patch-storage_src_mozStorageService.cpp,v 1.1 2012/04/26 13:30:30 ryoon Exp $

* Support jemalloc on *BSD

--- storage/src/mozStorageService.cpp.orig	2012-04-04 04:25:45.000000000 +0000
+++ storage/src/mozStorageService.cpp
@@ -515,7 +515,7 @@ sqlite3_vfs *ConstructTelemetryVFS();
 
 #ifdef MOZ_MEMORY
 
-#  if defined(XP_WIN) || defined(SOLARIS) || defined(ANDROID) || defined(XP_MACOSX)
+#  if defined(XP_WIN) || defined(SOLARIS) || defined(ANDROID) || defined(XP_MACOSX) || defined(XP_BSD)
 #    include "jemalloc.h"
 #  elif defined(XP_LINUX)
 // jemalloc is directly linked into firefox-bin; libxul doesn't link
@@ -565,7 +565,10 @@ static int sqliteMemSize(void *p)
 
 static int sqliteMemRoundup(int n)
 {
-  n = je_malloc_usable_size_in_advance(n);
+  if (je_malloc_usable_size_in_advance)
+  {
+      n = je_malloc_usable_size_in_advance(n);
+  }
 
   // jemalloc can return blocks of size 2 and 4, but SQLite requires that all
   // allocations be 8-aligned.  So we round up sub-8 requests to 8.  This
