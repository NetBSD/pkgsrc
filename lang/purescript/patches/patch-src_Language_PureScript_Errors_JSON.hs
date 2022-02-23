$NetBSD: patch-src_Language_PureScript_Errors_JSON.hs,v 1.1 2022/02/23 16:22:33 pho Exp $

Fix build with GHC 9.2

--- src/Language/PureScript/Errors/JSON.hs.orig	2022-02-20 18:03:10.579584907 +0000
+++ src/Language/PureScript/Errors/JSON.hs
@@ -39,9 +39,9 @@ data JSONResult = JSONResult
   } deriving (Show, Eq)
 
 $(A.deriveJSON A.defaultOptions ''ErrorPosition)
+$(A.deriveJSON A.defaultOptions ''ErrorSuggestion)
 $(A.deriveJSON A.defaultOptions ''JSONError)
 $(A.deriveJSON A.defaultOptions ''JSONResult)
-$(A.deriveJSON A.defaultOptions ''ErrorSuggestion)
 
 toJSONErrors :: Bool -> P.Level -> P.MultipleErrors -> [JSONError]
 toJSONErrors verbose level = map (toJSONError verbose level) . P.runMultipleErrors
