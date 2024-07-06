$NetBSD: patch-3rd_bee.lua_bee_thread_atomic__sync.cpp,v 1.1 2024/07/06 10:57:00 riastradh Exp $

https://github.com/actboy168/bee.lua/pull/50

--- 3rd/bee.lua/bee/thread/atomic_sync.cpp.orig	2024-04-23 08:56:20.000000000 +0000
+++ 3rd/bee.lua/bee/thread/atomic_sync.cpp
@@ -50,7 +50,11 @@ static void futex_wait(const int* ptr, i
 #    if defined(__linux__)
     ::syscall(SYS_futex, ptr, FUTEX_WAIT | FUTEX_PRIVATE_FLAG, val, timeout, 0, 0);
 #    elif defined(__NetBSD__)
-    ::syscall(SYS___futex, ptr, FUTEX_WAIT | FUTEX_PRIVATE_FLAG, val, timeout, 0, 0, 0);
+    struct timespec ts = {
+        .tv_sec = timeout.tv_sec,
+        .tv_nsec = timeout.tv,
+    };
+    ::syscall(SYS___futex, ptr, FUTEX_WAIT | FUTEX_PRIVATE_FLAG, val, &ts, 0, 0, 0);
 #    elif defined(__OpenBSD__)
     static_assert(sizeof(FutexTimespec) == sizeof(timespec));
     ::futex((uint32_t*)const_cast<int*>(ptr), FUTEX_WAIT | FUTEX_PRIVATE_FLAG, val, (const timespec*)timeout, 0);
