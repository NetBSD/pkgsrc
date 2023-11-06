$NetBSD: patch-src_Core_Options.idr,v 1.1 2023/11/06 17:17:51 pho Exp $

Hunk #0, #1, #2:
  Add DESTDIR support.

  TODO: Upstream this

--- src/Core/Options.idr.orig	2022-10-27 15:43:33.000000000 +0000
+++ src/Core/Options.idr
@@ -22,6 +22,7 @@ record Dirs where
   build_dir : String -- build directory, relative to working directory
   depends_dir : String -- local dependencies directory, relative to working directory
   output_dir : Maybe String -- output directory, relative to working directory
+  stage_dir : Maybe String -- staged installation directory
   prefix_dir : String -- installation prefix, for finding data files (e.g. run time support)
   extra_dirs : List String -- places to look for import files
   package_dirs : List String -- places to look for packages
@@ -38,12 +39,13 @@ outputDirWithDefault d = fromMaybe (buil
 
 public export
 toString : Dirs -> String
-toString d@(MkDirs wdir sdir bdir ldir odir dfix edirs pdirs ldirs ddirs) = """
+toString d@(MkDirs wdir sdir bdir ldir odir ddir dfix edirs pdirs ldirs ddirs) = """
   + Working Directory      :: \{ show wdir }
   + Source Directory       :: \{ show sdir }
   + Build Directory        :: \{ show bdir }
   + Local Depend Directory :: \{ show ldir }
   + Output Directory       :: \{ show $ outputDirWithDefault d }
+  + Stage Directory        :: \{ show ddir }
   + Installation Prefix    :: \{ show dfix }
   + Extra Directories      :: \{ show edirs }
   + Package Directories    :: \{ show pdirs }
@@ -210,7 +212,7 @@ getCG o cg = lookup (toLower cg) (availa
 
 defaultDirs : Dirs
 defaultDirs = MkDirs "." Nothing "build" "depends" Nothing
-                     "/usr/local" ["."] [] [] []
+                     Nothing "/usr/local" ["."] [] [] []
 
 defaultPPrint : PPrinter
 defaultPPrint = MkPPOpts False False True False
