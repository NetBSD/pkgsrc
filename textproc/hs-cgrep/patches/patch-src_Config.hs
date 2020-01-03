$NetBSD: patch-src_Config.hs,v 1.1 2020/01/03 08:22:09 pho Exp $

Compatibility with GHC < 8

--- src/Config.hs.orig	2001-09-09 01:46:40.000000000 +0000
+++ src/Config.hs
@@ -19,6 +19,11 @@
 {-# LANGUAGE DeriveGeneric #-}
 {-# LANGUAGE RecordWildCards #-}
 {-# LANGUAGE OverloadedStrings #-}
+{-# LANGUAGE CPP #-}
+
+#if !MIN_VERSION_base(4,9,0)
+#  define errorWithoutStackTrace error
+#endif
 
 module Config where
 
