$NetBSD: patch-libraries_ghc-internal_src_GHC_Internal_Event_KQueue.hsc,v 1.1 2025/01/29 13:21:53 pho Exp $

Use the correct symbol by going through the C header as opposed to directly
referencing a symbol in libc.

--- libraries/ghc-internal/src/GHC/Internal/Event/KQueue.hsc.orig	2025-01-09 08:41:34.532911672 +0000
+++ libraries/ghc-internal/src/GHC/Internal/Event/KQueue.hsc
@@ -299,7 +299,7 @@ foreign import capi safe "sys/event.h ke
     c_kevent :: KQueueFd -> Ptr Event -> CInt -> Ptr Event -> CInt
              -> Ptr TimeSpec -> IO CInt
 
-foreign import ccall unsafe "kevent"
+foreign import capi unsafe "sys/event.h kevent"
     c_kevent_unsafe :: KQueueFd -> Ptr Event -> CInt -> Ptr Event -> CInt
                     -> Ptr TimeSpec -> IO CInt
 #else
