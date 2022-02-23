$NetBSD: patch-src_Data_Aeson_BetterErrors_Internal.hs,v 1.1 2022/02/23 16:08:53 pho Exp $

Fix build with aeson-2.0

--- src/Data/Aeson/BetterErrors/Internal.hs.orig	2022-02-20 12:31:25.835056290 +0000
+++ src/Data/Aeson/BetterErrors/Internal.hs
@@ -33,7 +33,8 @@ import Data.Vector ((!?))
 import qualified Data.Vector as V
 import Data.Scientific (Scientific)
 import qualified Data.Scientific as S
-import qualified Data.HashMap.Strict as HashMap
+import Data.Aeson.Key (Key)
+import qualified Data.Aeson.KeyMap as KeyMap
 
 import Data.Aeson.BetterErrors.Utils
 
@@ -178,7 +179,7 @@ setValue v r = r { rdrValue = v }
 -- Internally, a list of these is maintained as the parser traverses the JSON
 -- data. This list is included in the error if one occurs.
 data PathPiece
-  = ObjectKey Text
+  = ObjectKey Key
   | ArrayIndex Int
   deriving (Show, Eq, Ord)
 
@@ -201,7 +202,7 @@ type ParseError' = ParseError Void
 -- but a value of the required type could not be constructed from it, for some
 -- reason.
 data ErrorSpecifics err
-  = KeyMissing Text
+  = KeyMissing Key
   | OutOfBounds Int
   | WrongType JSONType A.Value -- ^ Expected type, actual value
   | ExpectedIntegral Double
@@ -369,25 +370,25 @@ perhaps p = do
     _      -> Just <$> p
 
 -- | Take the value corresponding to a given key in the current object.
-key :: (Functor m, Monad m) => Text -> ParseT err m a -> ParseT err m a
+key :: (Functor m, Monad m) => Key -> ParseT err m a -> ParseT err m a
 key k p = key' (badSchema (KeyMissing k)) k p
 
 -- | Take the value corresponding to a given key in the current object, or
 -- if no property exists with that key, use the supplied default.
-keyOrDefault :: (Functor m, Monad m) => Text -> a -> ParseT err m a -> ParseT err m a
+keyOrDefault :: (Functor m, Monad m) => Key -> a -> ParseT err m a -> ParseT err m a
 keyOrDefault k def p = key' (pure def) k p
 
 -- | Take the value corresponding to a given key in the current object, or
 -- if no property exists with that key, return Nothing .
-keyMay :: (Functor m, Monad m) => Text -> ParseT err m a -> ParseT err m (Maybe a)
+keyMay :: (Functor m, Monad m) => Key -> ParseT err m a -> ParseT err m (Maybe a)
 keyMay k p = keyOrDefault k Nothing (Just <$> p)
 
-key' :: (Functor m, Monad m) => ParseT err m a -> Text -> ParseT err m a -> ParseT err m a
+key' :: (Functor m, Monad m) => ParseT err m a -> Key -> ParseT err m a -> ParseT err m a
 key' onMissing k p = do
   v <- asks rdrValue
   case v of
     A.Object obj ->
-      case HashMap.lookup k obj of
+      case KeyMap.lookup k obj of
         Just v' ->
           local (appendPath (ObjectKey k) . setValue v') p
         Nothing ->
@@ -433,21 +434,21 @@ eachInArray p = do
 
 -- | Parse each property in an object with the given parser, given the key as
 -- an argument, and collect the results.
-forEachInObject :: (Functor m, Monad m) => (Text -> ParseT err m a) -> ParseT err m [a]
+forEachInObject :: (Functor m, Monad m) => (Key -> ParseT err m a) -> ParseT err m [a]
 forEachInObject p = do
-  xs <- HashMap.toList <$> asObject
+  xs <- KeyMap.toList <$> asObject
   forM xs $ \(k, x) ->
     local (appendPath (ObjectKey k) . setValue x) (p k)
 
 -- | Attempt to parse each property value in the object with the given parser,
 -- and collect the results.
-eachInObject :: (Functor m, Monad m) => ParseT err m a -> ParseT err m [(Text, a)]
+eachInObject :: (Functor m, Monad m) => ParseT err m a -> ParseT err m [(Key, a)]
 eachInObject = eachInObjectWithKey Right
 
 -- | Attempt to parse each property in the object: parse the key with the
 -- given validation function, parse the value with the given parser, and
 -- collect the results.
-eachInObjectWithKey :: (Functor m, Monad m) => (Text -> Either err k) -> ParseT err m a -> ParseT err m [(k, a)]
+eachInObjectWithKey :: (Functor m, Monad m) => (Key -> Either err k) -> ParseT err m a -> ParseT err m [(k, a)]
 eachInObjectWithKey parseKey parseVal = forEachInObject $ \k ->
   (,) <$> liftEither (parseKey k) <*> parseVal
 
