$NetBSD: patch-src_Idris_REPL.hs,v 1.1 2021/04/25 11:39:03 pho Exp $

Fix build with haskeline-0.8.*.

--- src/Idris/REPL.hs.orig	2021-04-25 10:35:54.491750352 +0000
+++ src/Idris/REPL.hs
@@ -25,6 +25,7 @@ import Control.Concurrent.Async (race)
 import Control.DeepSeq
 import qualified Control.Exception as X
 import Control.Monad
+import Control.Monad.Catch (catch)
 import Control.Monad.Trans (lift)
 import Control.Monad.Trans.Except (runExceptT)
 import Control.Monad.Trans.State.Strict (evalStateT, get, put)
@@ -122,13 +123,13 @@ repl orig mods efile
                              (if colour && not isWindows
                                 then colourisePrompt theme str
                                 else str) ++ " "
-        x <- H.catch (H.withInterrupt $ getInputLine prompt)
+        x <- catch (H.withInterrupt $ getInputLine prompt)
                      (ctrlC (return $ Just ""))
         case x of
             Nothing -> do lift $ when (not quiet) (iputStrLn "Bye bye")
                           return ()
             Just input -> -- H.catch
-                do ms <- H.catch (H.withInterrupt $ lift $ processInput input orig mods efile)
+                do ms <- catch (H.withInterrupt $ lift $ processInput input orig mods efile)
                                  (ctrlC (return (Just mods)))
                    case ms of
                         Just mods -> let efile' = fromMaybe efile (listToMaybe mods)
@@ -136,7 +137,7 @@ repl orig mods efile
                         Nothing -> return ()
 --                             ctrlC)
 --       ctrlC
-   where ctrlC :: InputT Idris a -> SomeException -> InputT Idris a
+   where ctrlC :: InputT Idris a -> X.SomeException -> InputT Idris a
          ctrlC act e = do lift $ iputStrLn (show e)
                           act -- repl orig mods
 
