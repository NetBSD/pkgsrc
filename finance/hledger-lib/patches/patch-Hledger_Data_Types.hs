$NetBSD: patch-Hledger_Data_Types.hs,v 1.1 2022/02/12 07:50:32 pho Exp $

Fix build with GHC 9.2
https://github.com/simonmichael/hledger/issues/1774

--- Hledger/Data/Types.hs.orig	2022-02-10 07:41:12.915234936 +0000
+++ Hledger/Data/Types.hs
@@ -23,7 +23,7 @@ For more detailed documentation on each 
 {-# LANGUAGE RecordWildCards      #-}
 {-# LANGUAGE StandaloneDeriving   #-}
 
-module Hledger.Data.Types
+module Hledger.Data.Types (module Hledger.Data.Types, Year)
 where
 
 import GHC.Generics (Generic)
@@ -38,7 +38,7 @@ import Data.List (intercalate)
 import qualified Data.Map as M
 import Data.Ord (comparing)
 import Data.Text (Text)
-import Data.Time.Calendar (Day)
+import Data.Time.Calendar (Day, Year)
 import Data.Time.Clock.POSIX (POSIXTime)
 import Data.Time.LocalTime (LocalTime)
 import Data.Word (Word8)
@@ -78,7 +78,6 @@ data DateSpan = DateSpan (Maybe Day) (Ma
 instance Default DateSpan where def = DateSpan Nothing Nothing
 
 -- synonyms for various date-related scalars
-type Year = Integer
 type Month = Int     -- 1-12
 type Quarter = Int   -- 1-4
 type YearWeek = Int  -- 1-52
