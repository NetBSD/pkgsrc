$NetBSD: patch-BuildTools_SCons_SConscript.boot,v 1.3 2022/05/03 20:03:31 nia Exp $

Don't strip environment so pkgsrc settings survive.

--- BuildTools/SCons/SConscript.boot.orig	2018-04-06 10:06:45.000000000 +0000
+++ BuildTools/SCons/SConscript.boot
@@ -126,11 +126,7 @@ vars.Add(PathVariable("sparkle_public_ds
 # Set up default build & configure environment
 ################################################################################
 
-env_ENV = {
-    'PATH' : os.environ['PATH'],
-    'LD_LIBRARY_PATH' : os.environ.get("LD_LIBRARY_PATH", ""),
-    'TERM' : os.environ.get("TERM", ""),
-}
+env_ENV = os.environ
 
 if "MSVC_VERSION" in ARGUMENTS :
     env = Environment(ENV = env_ENV, variables = vars, MSVC_VERSION = ARGUMENTS["MSVC_VERSION"], platform = ARGUMENTS.get("PLATFORM", None))
