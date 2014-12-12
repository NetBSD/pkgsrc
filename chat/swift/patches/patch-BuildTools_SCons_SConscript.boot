$NetBSD: patch-BuildTools_SCons_SConscript.boot,v 1.1 2014/12/12 10:50:49 joerg Exp $

--- BuildTools/SCons/SConscript.boot.orig	2014-12-11 23:47:38.000000000 +0000
+++ BuildTools/SCons/SConscript.boot
@@ -65,10 +65,7 @@ vars.Add(BoolVariable("set_iterator_debu
 # Set up default build & configure environment
 ################################################################################
 
-env_ENV = {
-  'PATH' : os.environ['PATH'], 
-  'LD_LIBRARY_PATH' : os.environ.get("LD_LIBRARY_PATH", ""),
-}
+env_ENV = os.environ
 if "MSVC_VERSION" in ARGUMENTS :
   env = Environment(ENV = env_ENV, variables = vars, MSVC_VERSION = ARGUMENTS["MSVC_VERSION"])
 else :
