$NetBSD: patch-libraries_unix_System_Posix_User_ByteString.hsc,v 1.1 2024/04/28 05:58:58 pho Exp $

Suppress linker warnings about compatibility symbols by using "capi"
instead of "ccall".

--- libraries/unix/System/Posix/User/ByteString.hsc.orig	2023-10-24 03:45:34.747217813 +0000
+++ libraries/unix/System/Posix/User/ByteString.hsc
@@ -522,9 +522,9 @@ getAllUserEntries = lockpw GETALL $ brac
             else do thisentry <- unpackUserEntry ppw
                     worker (thisentry : accum)
 
-foreign import ccall safe "getpwent" c_getpwent :: IO (Ptr CPasswd)
-foreign import ccall safe "setpwent" c_setpwent :: IO ()
-foreign import ccall safe "endpwent" c_endpwent :: IO ()
+foreign import capi safe "HsUnix.h getpwent" c_getpwent :: IO (Ptr CPasswd)
+foreign import capi safe "HsUnix.h setpwent" c_setpwent :: IO ()
+foreign import capi safe "HsUnix.h endpwent" c_endpwent :: IO ()
 #else
 {-# WARNING getAllUserEntries "System.Posix.User.getAllUserEntries: not supported" #-}
 getAllUserEntries = error "System.Posix.User.getAllUserEntries: not supported"
