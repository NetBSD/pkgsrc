$NetBSD: patch-System_Locale_SetLocale.hsc,v 1.1 2021/04/23 12:40:46 pho Exp $

Suppress linker warnings about compatibility symbols by using "capi"
instead of "ccall".

--- System/Locale/SetLocale.hsc.orig	2021-04-23 12:38:45.139148092 +0000
+++ System/Locale/SetLocale.hsc
@@ -1,5 +1,6 @@
 {-# LANGUAGE DeriveDataTypeable
            , ForeignFunctionInterface #-}
+{-# LANGUAGE CApiFFI #-}
 
 -- Copyright (c) 2014, Sven Bartscher
 -- Look the file LICENSE.txt in the toplevel directory of the source tree for
@@ -44,7 +45,7 @@ categoryToCInt LC_MONETARY = #const LC_M
 categoryToCInt LC_NUMERIC = #const LC_NUMERIC
 categoryToCInt LC_TIME = #const LC_TIME
 
-foreign import ccall "locale.h setlocale" c_setlocale :: CInt -> CString -> IO CString
+foreign import capi "locale.h setlocale" c_setlocale :: CInt -> CString -> IO CString
 
 setLocale :: Category -> Maybe String -> IO (Maybe String)
 #ifndef LC_MESSAGES
