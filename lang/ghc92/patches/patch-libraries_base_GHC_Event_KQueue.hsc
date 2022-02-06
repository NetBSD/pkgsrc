$NetBSD: patch-libraries_base_GHC_Event_KQueue.hsc,v 1.1 2022/02/06 05:36:16 pho Exp $

Suppress linker warnings about compatibility syscall wrappers by using
"capi" instead of "ccall".

--- libraries/base/GHC/Event/KQueue.hsc.orig	2019-12-26 18:05:56.276488590 +0000
+++ libraries/base/GHC/Event/KQueue.hsc
@@ -284,7 +284,7 @@ foreign import capi safe "sys/event.h ke
     c_kevent :: KQueueFd -> Ptr Event -> CInt -> Ptr Event -> CInt
              -> Ptr TimeSpec -> IO CInt
 
-foreign import ccall unsafe "kevent"
+foreign import capi unsafe "sys/event.h kevent"
     c_kevent_unsafe :: KQueueFd -> Ptr Event -> CInt -> Ptr Event -> CInt
                     -> Ptr TimeSpec -> IO CInt
 #else
