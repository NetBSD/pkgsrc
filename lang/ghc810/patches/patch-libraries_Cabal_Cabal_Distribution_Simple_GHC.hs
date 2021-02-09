$NetBSD: patch-libraries_Cabal_Cabal_Distribution_Simple_GHC.hs,v 1.1 2021/02/09 13:16:24 ryoon Exp $

Enable Cabal's rpath overriding functionality on all the platforms
known to use ELF.

When a Cabal package which defins both a library and an executable is
to be built, GHC by default embeds an rpath to the *build* directory
into the executable. This may sound like a bug in GHC but is actually
not, because GHC doesn't know the fact that the said library is going
to be installed elsewhere. To overcome this issue, Cabal has a
functionality to disable the default rpath handling of GHC and
construct the correct set of rpaths... but only on certain platforms
for some reason.

--- libraries/Cabal/Cabal/Distribution/Simple/GHC.hs.orig	2020-01-16 22:47:21.132921936 +0000
+++ libraries/Cabal/Cabal/Distribution/Simple/GHC.hs
@@ -1725,10 +1725,10 @@ getRPaths lbi clbi | supportRPaths hostO
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
