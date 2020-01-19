$NetBSD: patch-Cheapskate_ParserCombinators.hs,v 1.1 2020/01/19 12:08:08 pho Exp $

Fix build with recent GHC.

--- Cheapskate/ParserCombinators.hs.orig	2020-01-19 12:04:49.545981538 +0000
+++ Cheapskate/ParserCombinators.hs
@@ -35,6 +35,7 @@ import Prelude hiding (takeWhile)
 import Data.Text (Text)
 import qualified Data.Text as T
 import Control.Monad
+import Control.Monad.Fail
 import Control.Applicative
 import qualified Data.Set as Set
 
@@ -109,7 +110,6 @@ instance Alternative Parser where
 
 instance Monad Parser where
   return x = Parser $ \st -> Right (st, x)
-  fail e = Parser $ \st -> Left $ ParseError (position st) e
   p >>= g = Parser $ \st ->
     case evalParser p st of
          Left e        -> Left e
@@ -117,6 +117,9 @@ instance Monad Parser where
   {-# INLINE return #-}
   {-# INLINE (>>=) #-}
 
+instance MonadFail Parser where
+  fail e = Parser $ \st -> Left $ ParseError (position st) e
+
 instance MonadPlus Parser where
   mzero = Parser $ \st -> Left $ ParseError (position st) "(mzero)"
   mplus p1 p2 = Parser $ \st ->
