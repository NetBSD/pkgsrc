$NetBSD: patch-libraries_Cabal_Cabal_src_Distribution_Simple_GHC.hs,v 1.1 2025/01/29 15:28:29 pho Exp $

Install Cabal packages built with ./Setup into
"$PREFIX/lib/{arch}-ghc-{version}" but not
"$PREFIX/lib/{arch}-ghc-{version}-inplace". The suffix "-inplace" stems
from "Project Unit Id" found in the result of "ghc --info", which comes
from generateConfigHs in "${WRKSRC}/hadrian/src/Rules/Generate.hs".

It isn't fundamentally bad, that is, Cabal packages would have no problem
having the suffix in the installation path. However, it's very bad in our
case because it breaks every single PLIST file of pkgsrc Haskell
packages. pho@ believes this is an upstream bug: Cabal should have no
fundamental reason to inherit the ABI tag of the ghc-as-a-library
package. Or at least it shouldn't treat "inplace" as a genuine ABI tag that
needs inheriting. "inplace" is a dummy tag after all.

TODO: Report this to Cabal folks. pho@ doesn't know how to fix this
properly. This is only a workaround that potentially has downsides.

--- libraries/Cabal/Cabal/src/Distribution/Simple/GHC.hs.orig	2025-01-29 14:28:52.172116521 +0000
+++ libraries/Cabal/Cabal/src/Distribution/Simple/GHC.hs
@@ -240,7 +240,7 @@ configure verbosity hcPath hcPkgPath con
       compilerId = CompilerId GHC ghcVersion
 
       compilerAbiTag :: AbiTag
-      compilerAbiTag = maybe NoAbiTag AbiTag (Map.lookup "Project Unit Id" ghcInfoMap >>= stripPrefix (prettyShow compilerId <> "-"))
+      compilerAbiTag = NoAbiTag
 
   let comp =
         Compiler
