$NetBSD: patch-src_Language_PureScript_CoreFn_ToJSON.hs,v 1.1 2022/02/23 16:22:33 pho Exp $

Fix build with aeson-2.0

--- src/Language/PureScript/CoreFn/ToJSON.hs.orig	2022-02-20 17:44:35.893792664 +0000
+++ src/Language/PureScript/CoreFn/ToJSON.hs
@@ -13,6 +13,7 @@ import           Control.Arrow ((***))
 import           Data.Either (isLeft)
 import qualified Data.Map.Strict as M
 import           Data.Aeson
+import qualified Data.Aeson.Key as Key
 import           Data.Version (Version, showVersion)
 import           Data.Text (Text)
 import qualified Data.Text as T
@@ -23,6 +24,10 @@ import           Language.PureScript.Cor
 import           Language.PureScript.Names
 import           Language.PureScript.PSString (PSString)
 
+mkKey :: String -> Key
+{-# INLINE mkKey #-}
+mkKey = Key.fromText . T.pack
+
 constructorTypeToJSON :: ConstructorType -> Value
 constructorTypeToJSON ProductType = toJSON "ProductType"
 constructorTypeToJSON SumType = toJSON "SumType"
@@ -30,61 +35,61 @@ constructorTypeToJSON SumType = toJSON "
 metaToJSON :: Meta -> Value
 metaToJSON (IsConstructor t is)
   = object
-    [ T.pack "metaType"         .= "IsConstructor"
-    , T.pack "constructorType"  .= constructorTypeToJSON t
-    , T.pack "identifiers"      .= identToJSON `map` is
-    ]
-metaToJSON IsNewtype              = object [ T.pack "metaType"  .= "IsNewtype" ]
-metaToJSON IsTypeClassConstructor = object [ T.pack "metaType"  .= "IsTypeClassConstructor" ]
-metaToJSON IsForeign              = object [ T.pack "metaType"  .= "IsForeign" ]
-metaToJSON IsWhere                = object [ T.pack "metaType"  .= "IsWhere" ]
+    [ mkKey "metaType"         .= "IsConstructor"
+    , mkKey "constructorType"  .= constructorTypeToJSON t
+    , mkKey "identifiers"      .= identToJSON `map` is
+    ]
+metaToJSON IsNewtype              = object [ mkKey "metaType"  .= "IsNewtype" ]
+metaToJSON IsTypeClassConstructor = object [ mkKey "metaType"  .= "IsTypeClassConstructor" ]
+metaToJSON IsForeign              = object [ mkKey "metaType"  .= "IsForeign" ]
+metaToJSON IsWhere                = object [ mkKey "metaType"  .= "IsWhere" ]
 
 sourceSpanToJSON :: SourceSpan -> Value
 sourceSpanToJSON (SourceSpan _ spanStart spanEnd) =
-  object [ T.pack "start" .= spanStart
-         , T.pack "end"   .= spanEnd
+  object [ mkKey "start" .= spanStart
+         , mkKey "end"   .= spanEnd
          ]
 
 annToJSON :: Ann -> Value
-annToJSON (ss, _, _, m) = object [ T.pack "sourceSpan"  .= sourceSpanToJSON ss
-                                 , T.pack "meta"        .= maybe Null metaToJSON m
+annToJSON (ss, _, _, m) = object [ mkKey "sourceSpan"  .= sourceSpanToJSON ss
+                                 , mkKey "meta"        .= maybe Null metaToJSON m
                                  ]
 
 literalToJSON :: (a -> Value) -> Literal a -> Value
 literalToJSON _ (NumericLiteral (Left n))
   = object
-    [ T.pack "literalType" .= "IntLiteral"
-    , T.pack "value"       .= n
+    [ mkKey "literalType" .= "IntLiteral"
+    , mkKey "value"       .= n
     ]
 literalToJSON _ (NumericLiteral (Right n))
   = object
-      [ T.pack "literalType"  .= "NumberLiteral"
-      , T.pack "value"        .= n
+      [ mkKey "literalType"  .= "NumberLiteral"
+      , mkKey "value"        .= n
       ]
 literalToJSON _ (StringLiteral s)
   = object
-    [ T.pack "literalType"  .= "StringLiteral"
-    , T.pack "value"        .= s
+    [ mkKey "literalType"  .= "StringLiteral"
+    , mkKey "value"        .= s
     ]
 literalToJSON _ (CharLiteral c)
   = object
-    [ T.pack "literalType"  .= "CharLiteral"
-    , T.pack "value"        .= c
+    [ mkKey "literalType"  .= "CharLiteral"
+    , mkKey "value"        .= c
     ]
 literalToJSON _ (BooleanLiteral b)
   = object
-    [ T.pack "literalType"  .= "BooleanLiteral"
-    , T.pack "value"        .= b
+    [ mkKey "literalType"  .= "BooleanLiteral"
+    , mkKey "value"        .= b
     ]
 literalToJSON t (ArrayLiteral xs)
   = object
-    [ T.pack "literalType"  .= "ArrayLiteral"
-    , T.pack "value"        .= map t xs
+    [ mkKey "literalType"  .= "ArrayLiteral"
+    , mkKey "value"        .= map t xs
     ]
 literalToJSON t (ObjectLiteral xs)
   = object
-    [ T.pack "literalType"    .= "ObjectLiteral"
-    , T.pack "value"          .= recordToJSON t xs
+    [ mkKey "literalType"    .= "ObjectLiteral"
+    , mkKey "value"          .= recordToJSON t xs
     ]
 
 identToJSON :: Ident -> Value
@@ -95,8 +100,8 @@ properNameToJSON = toJSON . runProperNam
 
 qualifiedToJSON :: (a -> Text) -> Qualified a -> Value
 qualifiedToJSON f (Qualified mn a) = object
-  [ T.pack "moduleName"   .= maybe Null moduleNameToJSON mn
-  , T.pack "identifier"   .= toJSON (f a)
+  [ mkKey "moduleName"   .= maybe Null moduleNameToJSON mn
+  , mkKey "identifier"   .= toJSON (f a)
   ]
 
 moduleNameToJSON :: ModuleName -> Value
@@ -104,22 +109,22 @@ moduleNameToJSON (ModuleName name) = toJ
 
 moduleToJSON :: Version -> Module Ann -> Value
 moduleToJSON v m = object
-  [ T.pack "sourceSpan" .= sourceSpanToJSON (moduleSourceSpan m)
-  , T.pack "moduleName" .= moduleNameToJSON (moduleName m)
-  , T.pack "modulePath" .= toJSON (modulePath m)
-  , T.pack "imports"    .= map importToJSON (moduleImports m)
-  , T.pack "exports"    .= map identToJSON (moduleExports m)
-  , T.pack "reExports"  .= reExportsToJSON (moduleReExports m)
-  , T.pack "foreign"    .= map identToJSON (moduleForeign m)
-  , T.pack "decls"      .= map bindToJSON (moduleDecls m)
-  , T.pack "builtWith"  .= toJSON (showVersion v)
-  , T.pack "comments"   .= map toJSON (moduleComments m)
+  [ mkKey "sourceSpan" .= sourceSpanToJSON (moduleSourceSpan m)
+  , mkKey "moduleName" .= moduleNameToJSON (moduleName m)
+  , mkKey "modulePath" .= toJSON (modulePath m)
+  , mkKey "imports"    .= map importToJSON (moduleImports m)
+  , mkKey "exports"    .= map identToJSON (moduleExports m)
+  , mkKey "reExports"  .= reExportsToJSON (moduleReExports m)
+  , mkKey "foreign"    .= map identToJSON (moduleForeign m)
+  , mkKey "decls"      .= map bindToJSON (moduleDecls m)
+  , mkKey "builtWith"  .= toJSON (showVersion v)
+  , mkKey "comments"   .= map toJSON (moduleComments m)
   ]
 
   where
   importToJSON (ann,mn) = object
-    [ T.pack "annotation" .= annToJSON ann
-    , T.pack "moduleName" .= moduleNameToJSON mn
+    [ mkKey "annotation" .= annToJSON ann
+    , mkKey "moduleName" .= moduleNameToJSON mn
     ]
 
   reExportsToJSON :: M.Map ModuleName [Ident] -> Value
@@ -128,19 +133,19 @@ moduleToJSON v m = object
 bindToJSON :: Bind Ann -> Value
 bindToJSON (NonRec ann n e)
   = object
-    [ T.pack "bindType"   .= "NonRec"
-    , T.pack "annotation" .= annToJSON ann
-    , T.pack "identifier" .= identToJSON n
-    , T.pack "expression" .= exprToJSON e
+    [ mkKey "bindType"   .= "NonRec"
+    , mkKey "annotation" .= annToJSON ann
+    , mkKey "identifier" .= identToJSON n
+    , mkKey "expression" .= exprToJSON e
     ]
 bindToJSON (Rec bs)
   = object
-    [ T.pack "bindType"   .= "Rec"
-    , T.pack "binds"      .= map (\((ann, n), e)
+    [ mkKey "bindType"   .= "Rec"
+    , mkKey "binds"      .= map (\((ann, n), e)
                                   -> object
-                                      [ T.pack "identifier"  .= identToJSON n
-                                      , T.pack "annotation"   .= annToJSON ann
-                                      , T.pack "expression"   .= exprToJSON e
+                                      [ mkKey "identifier"  .= identToJSON n
+                                      , mkKey "annotation"   .= annToJSON ann
+                                      , mkKey "expression"   .= exprToJSON e
                                       ]) bs
     ]
 
@@ -148,86 +153,86 @@ recordToJSON :: (a -> Value) -> [(PSStri
 recordToJSON f = toJSON . map (toJSON *** f)
 
 exprToJSON :: Expr Ann -> Value
-exprToJSON (Var ann i)              = object [ T.pack "type"        .= toJSON "Var"
-                                             , T.pack "annotation"  .= annToJSON ann
-                                             , T.pack "value"       .= qualifiedToJSON runIdent i
-                                             ]
-exprToJSON (Literal ann l)          = object [ T.pack "type"        .= "Literal"
-                                             , T.pack "annotation"  .= annToJSON ann
-                                             , T.pack "value"       .=  literalToJSON exprToJSON l
-                                             ]
-exprToJSON (Constructor ann d c is) = object [ T.pack "type"        .= "Constructor"
-                                             , T.pack "annotation"  .= annToJSON ann
-                                             , T.pack "typeName"    .= properNameToJSON d
-                                             , T.pack "constructorName" .= properNameToJSON c
-                                             , T.pack "fieldNames"  .= map identToJSON is
-                                             ]
-exprToJSON (Accessor ann f r)       = object [ T.pack "type"        .= "Accessor"
-                                             , T.pack "annotation"  .= annToJSON ann
-                                             , T.pack "fieldName"   .= f
-                                             , T.pack "expression"  .= exprToJSON r
-                                             ]
-exprToJSON (ObjectUpdate ann r fs)  = object [ T.pack "type"        .= "ObjectUpdate"
-                                             , T.pack "annotation"  .= annToJSON ann
-                                             , T.pack "expression"  .= exprToJSON r
-                                             , T.pack "updates"     .= recordToJSON exprToJSON fs
-                                             ]
-exprToJSON (Abs ann p b)            = object [ T.pack "type"        .= "Abs"
-                                             , T.pack "annotation"  .= annToJSON ann
-                                             , T.pack "argument"    .= identToJSON p
-                                             , T.pack "body"        .= exprToJSON b
-                                             ]
-exprToJSON (App ann f x)            = object [ T.pack "type"        .= "App"
-                                             , T.pack "annotation"  .= annToJSON ann
-                                             , T.pack "abstraction" .= exprToJSON f
-                                             , T.pack "argument"    .= exprToJSON x
-                                             ]
-exprToJSON (Case ann ss cs)         = object [ T.pack "type"        .= "Case"
-                                             , T.pack "annotation"  .= annToJSON ann
-                                             , T.pack "caseExpressions"
+exprToJSON (Var ann i)              = object [ mkKey "type"        .= toJSON "Var"
+                                             , mkKey "annotation"  .= annToJSON ann
+                                             , mkKey "value"       .= qualifiedToJSON runIdent i
+                                             ]
+exprToJSON (Literal ann l)          = object [ mkKey "type"        .= "Literal"
+                                             , mkKey "annotation"  .= annToJSON ann
+                                             , mkKey "value"       .=  literalToJSON exprToJSON l
+                                             ]
+exprToJSON (Constructor ann d c is) = object [ mkKey "type"        .= "Constructor"
+                                             , mkKey "annotation"  .= annToJSON ann
+                                             , mkKey "typeName"    .= properNameToJSON d
+                                             , mkKey "constructorName" .= properNameToJSON c
+                                             , mkKey "fieldNames"  .= map identToJSON is
+                                             ]
+exprToJSON (Accessor ann f r)       = object [ mkKey "type"        .= "Accessor"
+                                             , mkKey "annotation"  .= annToJSON ann
+                                             , mkKey "fieldName"   .= f
+                                             , mkKey "expression"  .= exprToJSON r
+                                             ]
+exprToJSON (ObjectUpdate ann r fs)  = object [ mkKey "type"        .= "ObjectUpdate"
+                                             , mkKey "annotation"  .= annToJSON ann
+                                             , mkKey "expression"  .= exprToJSON r
+                                             , mkKey "updates"     .= recordToJSON exprToJSON fs
+                                             ]
+exprToJSON (Abs ann p b)            = object [ mkKey "type"        .= "Abs"
+                                             , mkKey "annotation"  .= annToJSON ann
+                                             , mkKey "argument"    .= identToJSON p
+                                             , mkKey "body"        .= exprToJSON b
+                                             ]
+exprToJSON (App ann f x)            = object [ mkKey "type"        .= "App"
+                                             , mkKey "annotation"  .= annToJSON ann
+                                             , mkKey "abstraction" .= exprToJSON f
+                                             , mkKey "argument"    .= exprToJSON x
+                                             ]
+exprToJSON (Case ann ss cs)         = object [ mkKey "type"        .= "Case"
+                                             , mkKey "annotation"  .= annToJSON ann
+                                             , mkKey "caseExpressions"
                                                                     .= map exprToJSON ss
-                                             , T.pack "caseAlternatives"
+                                             , mkKey "caseAlternatives"
                                                                     .= map caseAlternativeToJSON cs
                                              ]
-exprToJSON (Let ann bs e)           = object [ T.pack "type"        .= "Let" 
-                                             , T.pack "annotation"  .= annToJSON ann
-                                             , T.pack "binds"       .= map bindToJSON bs
-                                             , T.pack "expression"  .= exprToJSON e
+exprToJSON (Let ann bs e)           = object [ mkKey "type"        .= "Let" 
+                                             , mkKey "annotation"  .= annToJSON ann
+                                             , mkKey "binds"       .= map bindToJSON bs
+                                             , mkKey "expression"  .= exprToJSON e
                                              ]
 
 caseAlternativeToJSON :: CaseAlternative Ann -> Value
 caseAlternativeToJSON (CaseAlternative bs r') =
   let isGuarded = isLeft r'
   in object
-      [ T.pack "binders"     .= toJSON (map binderToJSON bs)
-      , T.pack "isGuarded"   .= toJSON isGuarded
-      , T.pack (if isGuarded then "expressions" else "expression")
+      [ mkKey "binders"     .= toJSON (map binderToJSON bs)
+      , mkKey "isGuarded"   .= toJSON isGuarded
+      , mkKey (if isGuarded then "expressions" else "expression")
          .= case r' of
-             Left rs -> toJSON $ map (\(g, e) -> object [ T.pack "guard" .= exprToJSON g, T.pack "expression" .= exprToJSON e]) rs
+             Left rs -> toJSON $ map (\(g, e) -> object [ mkKey "guard" .= exprToJSON g, mkKey "expression" .= exprToJSON e]) rs
              Right r -> exprToJSON r
       ]
 
 binderToJSON :: Binder Ann -> Value
-binderToJSON (VarBinder ann v)              = object [ T.pack "binderType"  .= "VarBinder"
-                                                     , T.pack "annotation"  .= annToJSON ann
-                                                     , T.pack "identifier"  .= identToJSON v
+binderToJSON (VarBinder ann v)              = object [ mkKey "binderType"  .= "VarBinder"
+                                                     , mkKey "annotation"  .= annToJSON ann
+                                                     , mkKey "identifier"  .= identToJSON v
                                                      ]
-binderToJSON (NullBinder ann)               = object [ T.pack "binderType"  .= "NullBinder"
-                                                     , T.pack "annotation"  .= annToJSON ann
+binderToJSON (NullBinder ann)               = object [ mkKey "binderType"  .= "NullBinder"
+                                                     , mkKey "annotation"  .= annToJSON ann
                                                      ]
-binderToJSON (LiteralBinder ann l)          = object [ T.pack "binderType"  .= "LiteralBinder"
-                                                     , T.pack "annotation"  .= annToJSON ann
-                                                     , T.pack "literal"     .= literalToJSON binderToJSON l
+binderToJSON (LiteralBinder ann l)          = object [ mkKey "binderType"  .= "LiteralBinder"
+                                                     , mkKey "annotation"  .= annToJSON ann
+                                                     , mkKey "literal"     .= literalToJSON binderToJSON l
                                                      ]
-binderToJSON (ConstructorBinder ann d c bs) = object [ T.pack "binderType"  .= "ConstructorBinder"
-                                                     , T.pack "annotation"  .= annToJSON ann
-                                                     , T.pack "typeName"    .= qualifiedToJSON runProperName d
-                                                     , T.pack "constructorName"
+binderToJSON (ConstructorBinder ann d c bs) = object [ mkKey "binderType"  .= "ConstructorBinder"
+                                                     , mkKey "annotation"  .= annToJSON ann
+                                                     , mkKey "typeName"    .= qualifiedToJSON runProperName d
+                                                     , mkKey "constructorName"
                                                                             .= qualifiedToJSON runProperName c
-                                                     , T.pack "binders"     .= map binderToJSON bs
+                                                     , mkKey "binders"     .= map binderToJSON bs
                                                      ]
-binderToJSON (NamedBinder ann n b)          = object [ T.pack "binderType"  .= "NamedBinder"
-                                                     , T.pack "annotation"  .= annToJSON ann
-                                                     , T.pack "identifier"  .= identToJSON n
-                                                     , T.pack "binder"      .= binderToJSON b
+binderToJSON (NamedBinder ann n b)          = object [ mkKey "binderType"  .= "NamedBinder"
+                                                     , mkKey "annotation"  .= annToJSON ann
+                                                     , mkKey "identifier"  .= identToJSON n
+                                                     , mkKey "binder"      .= binderToJSON b
                                                      ]
