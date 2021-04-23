$NetBSD: patch-Network_Socket_Syscall.hs,v 1.1 2021/04/23 10:03:01 pho Exp $

Suppress a linker warning about compatibility symbol by using "capi"
instead of "ccall".

--- Network/Socket/Syscall.hs.orig	2021-04-23 10:00:54.224685354 +0000
+++ Network/Socket/Syscall.hs
@@ -1,3 +1,4 @@
+{-# LANGUAGE CApiFFI #-}
 {-# LANGUAGE CPP #-}
 
 #include "HsNetDef.h"
@@ -222,7 +223,7 @@ accept listing_sock = withNewSocketAddre
 # endif /* HAVE_ADVANCED_SOCKET_FLAGS */
 #endif
 
-foreign import CALLCONV unsafe "socket"
+foreign import capi unsafe "sys/socket.h socket"
   c_socket :: CInt -> CInt -> CInt -> IO CInt
 foreign import CALLCONV unsafe "bind"
   c_bind :: CInt -> Ptr sa -> CInt{-CSockLen???-} -> IO CInt
