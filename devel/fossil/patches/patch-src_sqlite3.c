$NetBSD: patch-src_sqlite3.c,v 1.1 2019/10/05 20:53:01 gutteridge Exp $

SunOS needs alloca.h for alloca().

--- src/sqlite3.c.orig	2019-10-04 21:41:13.000000000 +0000
+++ src/sqlite3.c
@@ -18810,6 +18810,9 @@ SQLITE_PRIVATE int sqlite3HeapNearlyFull
 ** that deal with sqlite3StackAlloc() failures to be unreachable.
 */
 #ifdef SQLITE_USE_ALLOCA
+# ifdef __sun
+# include <alloca.h>
+# endif
 # define sqlite3StackAllocRaw(D,N)   alloca(N)
 # define sqlite3StackAllocZero(D,N)  memset(alloca(N), 0, N)
 # define sqlite3StackFree(D,P)
