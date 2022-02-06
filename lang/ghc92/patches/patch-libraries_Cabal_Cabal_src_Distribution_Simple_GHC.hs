$NetBSD: patch-libraries_Cabal_Cabal_src_Distribution_Simple_GHC.hs,v 1.1 2022/02/06 05:36:16 pho Exp $

Enable Cabal's rpath overriding functionality on all the platforms
known to use ELF.

When a Cabal package which defines both a library and an executable
to be built, GHC by default embeds an rpath to the *build* directory
into the executable. This may sound like a bug in GHC but is actually
not, because GHC doesn't know the fact that the said library is going
to be installed elsewhere. To overcome this issue, Cabal has a
functionality to disable the default rpath handling of GHC and
construct the correct set of rpaths... but only on certain platforms
for some reason.

Pull request: https://github.com/haskell/cabal/pull/7382

--- libraries/Cabal/Cabal/src/Distribution/Simple/GHC.hs.orig	2022-01-21 02:23:32.884988700 +0000
+++ libraries/Cabal/Cabal/src/Distribution/Simple/GHC.hs
@@ -1734,10 +1734,10 @@ getRPaths lbi clbi | supportRPaths hostO
       case compid of
         CompilerId GHC ver | ver >= mkVersion [7,10,2] -> True
         _                                              -> False
-    supportRPaths OpenBSD     = False
-    supportRPaths NetBSD      = False
-    supportRPaths DragonFly   = False
-    supportRPaths Solaris     = False
+    supportRPaths OpenBSD     = True
+    supportRPaths NetBSD      = True
+    supportRPaths DragonFly   = True
+    supportRPaths Solaris     = True
     supportRPaths AIX         = False
     supportRPaths HPUX        = False
     supportRPaths IRIX        = False
