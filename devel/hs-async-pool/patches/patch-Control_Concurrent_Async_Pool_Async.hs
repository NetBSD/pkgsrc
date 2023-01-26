$NetBSD: patch-Control_Concurrent_Async_Pool_Async.hs,v 1.1 2023/01/26 03:58:43 pho Exp $

Fix build with GHC 9.4:
https://github.com/jwiegley/async-pool/commit/c5b8e82be6496fd754ce78a4303bb177d6c6a6df

--- Control/Concurrent/Async/Pool/Async.hs.orig	2001-09-09 01:46:40.000000000 +0000
+++ Control/Concurrent/Async/Pool/Async.hs
@@ -710,10 +710,18 @@ tryAll = try
 -- exception handler.
 {-# INLINE rawForkIO #-}
 rawForkIO :: IO () -> IO ThreadId
+#if MIN_VERSION_base(4,17,0)
+rawForkIO (IO action) = IO $ \ s ->
+#else
 rawForkIO action = IO $ \ s ->
+#endif
    case (fork# action s) of (# s1, tid #) -> (# s1, ThreadId tid #)
 
 {-# INLINE rawForkOn #-}
 rawForkOn :: Int -> IO () -> IO ThreadId
+#if MIN_VERSION_base(4,17,0)
+rawForkOn (I# cpu) (IO action) = IO $ \ s ->
+#else
 rawForkOn (I# cpu) action = IO $ \ s ->
+#endif
    case (forkOn# cpu action s) of (# s1, tid #) -> (# s1, ThreadId tid #)
