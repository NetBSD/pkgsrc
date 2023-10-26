$NetBSD: patch-src_Language_Haskell_Exts_InternalParser.ly,v 1.1 2023/10/26 08:29:00 pho Exp $

Fix build with happy-1.21.0, but I'm not sure this is a proper fix.
https://github.com/haskell-suite/haskell-src-exts/issues/467

--- src/Language/Haskell/Exts/InternalParser.ly.orig	2020-06-02 02:35:42.000000000 +0000
+++ src/Language/Haskell/Exts/InternalParser.ly
@@ -2216,13 +2216,13 @@ Miscellaneous (mostly renamings)
         | 'family'		{ family_name     (nIS $1) }
 
 > qtyvarop_(ostar) :: { QName L }
-> qtyvarop_ : '`' tyvar '`'     { UnQual ($1 <^^> $3 <** [$1, srcInfoSpan (ann $2), $3]) $2 }
+>          : '`' tyvar '`'      { UnQual ($1 <^^> $3 <** [$1, srcInfoSpan (ann $2), $3]) $2 }
 >          | tyvarsym_(ostar)   { UnQual (ann $1) $1 }
 
 > tyvarsym_(ostar) :: { Name L }
-> tyvarsym : VARSYM              { let Loc l (VarSym x) = $1 in Symbol (nIS l) x }
+>          : VARSYM              { let Loc l (VarSym x) = $1 in Symbol (nIS l) x }
 >          | '-'                 { Symbol (nIS $1) "-" }
->          | ostar                   { Symbol (nIS $1) "*" }
+>          | ostar               { Symbol (nIS $1) "*" }
 
 > impdeclsblock :: { ([ImportDecl L],[S],L) }
 >               : '{'  optsemis impdecls optsemis '}'         { let (ids, ss) = $3 in (ids, $1 : reverse $2 ++ ss ++ reverse $4 ++ [$5], $1 <^^> $5) }
