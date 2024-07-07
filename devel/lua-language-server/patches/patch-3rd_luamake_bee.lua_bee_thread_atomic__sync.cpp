$NetBSD: patch-3rd_luamake_bee.lua_bee_thread_atomic__sync.cpp,v 1.1 2024/07/07 14:00:18 riastradh Exp $

https://github.com/actboy168/bee.lua/pull/50

--- 3rd/luamake/bee.lua/bee/thread/atomic_sync.cpp.orig	2024-04-23 01:38:34.000000000 +0000
+++ 3rd/luamake/bee.lua/bee/thread/atomic_sync.cpp
@@ -50,7 +50,10 @@ static void futex_wait(const int* ptr, i
 #    if defined(__linux__)
     ::syscall(SYS_futex, ptr, FUTEX_WAIT | FUTEX_PRIVATE_FLAG, val, timeout, 0, 0);
 #    elif defined(__NetBSD__)
-    ::syscall(SYS___futex, ptr, FUTEX_WAIT | FUTEX_PRIVATE_FLAG, val, timeout, 0, 0, 0);
+    struct timespec ts;
+    ts.tv_sec = timeout->tv_sec;
+    ts.tv_nsec = timeout->tv_nsec;
+    ::syscall(SYS___futex, ptr, FUTEX_WAIT | FUTEX_PRIVATE_FLAG, val, &ts, 0, 0, 0);
 #    elif defined(__OpenBSD__)
     static_assert(sizeof(FutexTimespec) == sizeof(timespec));
     ::futex((uint32_t*)const_cast<int*>(ptr), FUTEX_WAIT | FUTEX_PRIVATE_FLAG, val, (const timespec*)timeout, 0);
