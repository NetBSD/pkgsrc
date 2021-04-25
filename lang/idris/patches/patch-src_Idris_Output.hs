$NetBSD: patch-src_Idris_Output.hs,v 1.1 2021/04/25 11:39:03 pho Exp $

Fix build with haskeline-0.8.*. Not sure this is the right way to fix
it though (probably not), and it's not clear if the upstream is going
to fix this properly given that Idris 2 is going to supersede this
implementation.

--- src/Idris/Output.hs.orig	2021-04-25 10:27:19.932751280 +0000
+++ src/Idris/Output.hs
@@ -37,21 +37,13 @@ import Prelude hiding ((<$>))
 #endif
 
 import Control.Arrow (first)
-import Control.Monad.Trans.Except (ExceptT(ExceptT), runExceptT)
 import Data.List (intersperse, nub)
 import Data.Maybe (fromJust, fromMaybe, isJust, listToMaybe)
 import qualified Data.Set as S
-import System.Console.Haskeline.MonadException (MonadException(controlIO),
-                                                RunIO(RunIO))
 import System.FilePath (replaceExtension)
 import System.IO (Handle, hPutStr, hPutStrLn)
 import System.IO.Error (tryIOError)
 
-instance MonadException m => MonadException (ExceptT Err m) where
-    controlIO f = ExceptT $ controlIO $ \(RunIO run) -> let
-                    run' = RunIO (fmap ExceptT . run . runExceptT)
-                    in fmap runExceptT $ f run'
-
 pshow :: IState -> Err -> String
 pshow ist err = displayDecorated (consoleDecorate ist) .
                 renderPretty 1.0 80 .
