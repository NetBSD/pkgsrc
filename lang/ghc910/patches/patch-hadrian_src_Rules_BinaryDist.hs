$NetBSD: patch-hadrian_src_Rules_BinaryDist.hs,v 1.3 2025/12/28 07:30:17 pho Exp $

Hunk #1, #2, #4:
    Distinguish bootstrapping bindists from regular ones. This is
    pkgsrc-specific.

Hunk #3:
    Do not run `ghc-pkg recache' while creating a binary distribution. We
    don't want a package cache to be installed because we do it in our
    INSTALL script. Also it's not possible to run ghc-pkg in the first
    place without setting LD_LIBRARY_PATH since we don't build relocatable
    executables. This is pkgsrc-specific.

Hunk #5:
    We want our bootkits to be as small as possible, even though `xz -9e'
    is very slow and consumes about 680 MiB of memory. This is
    pkgsrc-specific.

Hunk #0, #6:
    Bundle pkgsrc-installed dependencies with bootkits. This is
    pkgsrc-specific.

--- hadrian/src/Rules/BinaryDist.hs.orig	2024-05-10 05:05:49.000000000 +0000
+++ hadrian/src/Rules/BinaryDist.hs
@@ -13,10 +13,15 @@ import Settings
 import Settings.Program (programContext)
 import Target
 import Utilities
+import qualified System.Directory as IO
 import qualified System.Directory.Extra as IO
+import Control.Monad.IO.Class (MonadIO)
 import Data.Either
+import Data.Set (Set)
 import qualified Data.Set as Set
 import Oracles.Flavour
+import qualified System.Environment as IO
+import System.Exit (ExitCode(..))
 
 {-
 Note [Binary distributions]
@@ -115,7 +120,7 @@ installTo relocatable prefix = do
     root <- buildRoot
     version        <- setting ProjectVersion
     targetPlatform <- setting TargetPlatformFull
-    let ghcVersionPretty = "ghc-" ++ version ++ "-" ++ targetPlatform
+    let ghcVersionPretty = "ghc-" ++ version ++ "-boot-" ++ targetPlatform
         bindistFilesDir  = root -/- "bindist" -/- ghcVersionPretty
     runBuilder (Configure bindistFilesDir) ["--prefix="++prefix] [] []
     let env = case relocatable of
@@ -154,7 +159,7 @@ bindistRules = do
 
         let ghcBuildDir      = root -/- stageString Stage1
             bindistFilesDir  = root -/- "bindist" -/- ghcVersionPretty
-            ghcVersionPretty = "ghc-" ++ version ++ "-" ++ targetPlatform
+            ghcVersionPretty = "ghc-" ++ version ++ "-boot-" ++ targetPlatform
             rtsIncludeDir    = ghcBuildDir -/- "lib" -/- distDir -/- rtsDir
                                -/- "include"
 
@@ -232,16 +237,9 @@ bindistRules = do
         copyDirectory (rtsIncludeDir)         bindistFilesDir
         when windowsHost $ createGhcii (bindistFilesDir -/- "bin")
 
-        -- Call ghc-pkg recache, after copying so the package.cache is
-        -- accurate, then it's on the distributor to use `cp -a` to install
-        -- a relocatable bindist.
-        --
-        -- N.B. the ghc-pkg executable may be prefixed with a target triple
-        -- (c.f. #20267).
-        ghcPkgName <- programName (vanillaContext Stage1 ghcPkg)
-        cmd_ (bindistFilesDir -/- "bin" -/- ghcPkgName) ["recache"]
-
-
+        bootkitRequested <- liftIO $ IO.lookupEnv "BUILDING_BOOTKIT"
+        when (isJust bootkitRequested) $
+          bundleVendorLibs bindistFilesDir
 
         -- TODO: we should only embed the docs that have been generated
         -- depending on the current settings (flavours' "ghcDocs" field and
@@ -319,7 +317,7 @@ bindistRules = do
             version        <- setting ProjectVersion
             targetPlatform <- setting TargetPlatformFull
 
-            let ghcVersionPretty = "ghc-" ++ version ++ "-" ++ targetPlatform
+            let ghcVersionPretty = "ghc-" ++ version ++ "-boot-" ++ targetPlatform
 
             -- Finally, we create the archive <root>/bindist/ghc-X.Y.Z-platform.tar.xz
             tarPath <- builderPath (Tar Create)
@@ -388,7 +386,7 @@ generateBuildMk = do
 -- | Flag to pass to tar to use the given 'Compressor'.
 compressorTarFlag :: Compressor -> String
 compressorTarFlag Gzip  = "--gzip"
-compressorTarFlag Xz    = "--xz"
+compressorTarFlag Xz    = "--use-compress-program=xz --verbose -9 --extreme"
 compressorTarFlag Bzip2 = "--bzip"
 
 -- | File extension to use for archives compressed with the given 'Compressor'.
@@ -556,3 +554,248 @@ createGhcii outDir = do
       , "exec \"$(dirname \"$0\")\"/ghc --interactive \"$@\""
       ]
 
+data ObjectFmt  = ELF | MachO      deriving (Show, Eq)
+data ObjectType = ObjExec | ObjLib deriving (Show, Eq)
+
+bundleVendorLibs :: FilePath -> Action ()
+bundleVendorLibs bindistDir =
+  -- For each native object in "bin" and "lib", iterate the list of library
+  -- dependencies. Copy any libraries not in a blocklist (including their
+  -- transitive dependencies) to lib/vendor/ and inject a relative RPATH.
+  do isELF   <- isElfTarget
+     isMachO <- isOsxTarget -- Strictly speaking this is wrong, as macOS
+                            -- isn't the only platform using Mach-O. But we
+                            -- can't do anything better at the moment.
+     fmt     <- case () of
+                  _ | isELF     -> pure ELF
+                  _ | isMachO   -> pure MachO
+                  _ | otherwise -> fail "Sorry but we don't know how to bundle vendor libraries for this target platform"
+     let prefixErr = "You must specify a path with --prefix when using the"
+                     ++ " 'install' rule"
+     prefix  <- addTrailingPathSeparator . fromMaybe (error prefixErr) <$> cmdPrefix
+     -- Bundled libraries go into "${ghclibdir}/lib/vendor" where ghclibdir
+     -- is "${prefix}/lib/ghc-${version}". The bindist Makefile installs
+     -- everything under "${ghclibdir}/lib" preserving the directory
+     -- structure so we don't need to modify it.
+     let destDir = bindistDir -/- "lib/vendor"
+     liftIO $ IO.removePathForcibly destDir
+     liftIO $ IO.createDirectory destDir
+     mapM_ (go fmt ObjExec prefix destDir)
+       =<< filterM isRegular
+       =<< liftIO (IO.listFiles (bindistDir -/- "bin"))
+     mapM_ (go fmt ObjLib  prefix destDir)
+       =<< filterM isRegular
+       =<< liftIO (IO.listFilesInside (pure . (/= destDir)) (bindistDir -/- "lib"))
+  where
+    isRegular :: FilePath -> Action Bool
+    isRegular = (not <$>) . liftIO . IO.pathIsSymbolicLink
+
+    go :: ObjectFmt -> ObjectType -> FilePath -> FilePath -> FilePath -> Action ()
+    go fmt typ prefix destDir path =
+      do bi   <- getBinInfo fmt typ path
+         deps <- biToDeps fmt bi
+         mapM_ (copyAndExamine fmt prefix destDir) deps
+         unless (all isBlockedDynDep deps) $
+           -- The file is not necessarily writable. Make sure it is, before
+           -- trying to patch it.
+           do perms <- liftIO $ IO.getPermissions path
+              let perms' = IO.setOwnerWritable True perms
+              liftIO $ IO.setPermissions path perms'
+              embedRPath fmt typ prefix destDir bi path
+
+    copyAndExamine :: ObjectFmt -> FilePath -> FilePath -> FilePath -> Action ()
+    copyAndExamine fmt prefix destDir depPath =
+      do copied <- copyDynDep destDir depPath
+         when copied $
+           -- Recursively bundle dependencies of this library.
+           do let copiedPath = replaceDirectory depPath destDir
+              go fmt ObjLib prefix destDir copiedPath
+
+data BinInfo =
+  BinInfo
+  { biNeeded :: !(Set FilePath)
+  , biRPaths :: ![FilePath]
+  }
+  deriving Show
+
+instance Semigroup BinInfo where
+  a <> b = BinInfo (biNeeded a <> biNeeded b) (biRPaths a <> biRPaths b)
+
+instance Monoid BinInfo where
+  mempty = BinInfo mempty mempty
+
+data MachOLoadCommand = LCLoadDylib | LCRPath
+  deriving (Show, Eq)
+
+getBinInfo :: ObjectFmt -> ObjectType -> FilePath -> Action BinInfo
+getBinInfo ELF typ path
+  | typ == ObjExec || "lib" `isPrefixOf` takeFileName path =
+      do (Exit c, Stdout out) <- cmd (EchoStderr False) "readelf" ["-Wd", path]
+         case c of
+           ExitFailure _ -> pure mempty -- Ignore the error; it's probably not an ELF object.
+           ExitSuccess   -> pure . foldl' go mempty $ lines out
+  | otherwise =
+      pure mempty -- This file isn't worth readelf-ing. Don't waste time.
+  where
+    go :: BinInfo -> String -> BinInfo
+    go bi line =
+      case words line of
+        (_ : ("(NEEDED)" : _)) ->
+          let dep = takeWhile (/= ']') . drop 1 . dropWhile (/= '[') $ line
+          in
+            bi { biNeeded = Set.insert dep (biNeeded bi) }
+
+        (_ : ("(RPATH)" : _)) ->
+          let paths = splitSearchPath . takeWhile (/= ']') . drop 1 . dropWhile (/= '[') $ line
+          in
+            bi { biRPaths = biRPaths bi <> paths }
+
+        _ -> bi -- Ignore this line.
+
+getBinInfo MachO typ path
+  | typ == ObjExec || "lib" `isPrefixOf` takeFileName path =
+      do (Exit c, Stdout out) <- cmd (EchoStderr False) "otool" ["-l", path]
+         case c of
+           ExitFailure _ -> pure mempty -- Ignore the error; it's probably not a Mach-O object.
+           ExitSuccess   -> pure . fst . foldl' go (mempty, Nothing) $ lines out
+  | otherwise =
+      pure mempty -- This file isn't worth otool-ing. Don't waste time.
+  where
+    go :: (BinInfo, Maybe MachOLoadCommand) -> String -> (BinInfo, Maybe MachOLoadCommand)
+    go (bi, cmd) line =
+      case words line of
+        ["cmd" , "LC_LOAD_DYLIB"] -> (bi, Just LCLoadDylib)
+        ["cmd" , "LC_RPATH"     ] -> (bi, Just LCRPath)
+        ("name":_)
+          | cmd == Just LCLoadDylib -> -- "name /usr/lib/libSystem.B.dylib (offset 24)"
+              let dep = extractValue "name" line
+              in
+                (bi { biNeeded = Set.insert dep (biNeeded bi) }, Nothing)
+        ("path":_)
+          | cmd == Just LCRPath -> -- "path /opt/pkg/lib (offset 12)"
+              let rpath = extractValue "path" line
+              in
+                (bi { biRPaths = biRPaths bi <> pure rpath }, Nothing)
+        _ -> -- Ignore everything else.
+          (bi, cmd)
+
+    extractValue :: String -> String -> String
+    extractValue key line =
+      let isSpace = (== ' ')
+          keyLen  = length key
+          value'  = dropWhile isSpace . drop keyLen . dropWhile isSpace $ line
+      in
+        -- Delete anything after the last occurence of '('.
+        reverse . dropWhile isSpace . drop 1 . dropWhile (/= '(') . reverse . dropWhile isSpace $ value'
+
+biToDeps :: (MonadFail m, MonadIO m) => ObjectFmt -> BinInfo -> m [FilePath]
+biToDeps ELF bi =
+  do def <- liftIO $ IO.getEnv "SYSTEM_DEFAULT_RPATH" -- Expected to be set by bootstrap.mk
+     mapM (findDep $ splitSearchPath def) (Set.toList (biNeeded bi))
+  where
+    findDep :: (MonadFail m, MonadIO m) => [FilePath] -> FilePath -> m FilePath
+    findDep defPaths depName =
+      do let rpaths = biRPaths bi <> defPaths
+         r <- liftIO $ IO.findFile rpaths depName
+         case r of
+           Nothing ->
+             -- This is bad enough for aborting with an error.
+             fail $ "Library " <> depName <> " not found in any of rpaths " <>
+                    intercalate [searchPathSeparator] rpaths
+           Just found ->
+             pure found
+
+-- macOS is weird. System libraries don't actually exist in the
+-- filesystem. And rpaths work very differently from ELF.
+biToDeps MachO bi =
+  do def <- liftIO $ IO.getEnv "SYSTEM_DEFAULT_RPATH" -- Expected to be set by bootstrap.mk
+     mapM (findDep $ splitSearchPath def) (Set.toList (biNeeded bi))
+  where
+    findDep :: (MonadFail m, MonadIO m) => [FilePath] -> FilePath -> m FilePath
+    findDep _ depPath@('@':_) =
+      fail $ "Relative dependency path (" <> depPath <>
+             ") is currently not supported. Poke pho@ when this error actually happens."
+    findDep defPaths depPath
+      | any ((`isPrefixOf` depPath) . addTrailingPathSeparator) defPaths =
+          -- This library most likely doesn't exist as an actual file.
+          pure depPath
+      | otherwise =
+          do e <- liftIO $ IO.doesFileExist depPath
+             if e
+               then pure depPath
+               -- This is bad enough for aborting with an error.
+               else fail $ "Library " <> depPath <> " not found"
+
+isBlockedDynDep :: FilePath -> Bool
+isBlockedDynDep = flip Set.member blockList . dropExtensions . takeFileName
+  where
+    -- These libraries are exempted from being bundled with the resulting
+    -- bootkit.
+    {-# NOINLINE blockList #-}
+    blockList :: Set FilePath
+    blockList =
+      Set.fromList
+      [ "libSystem"  -- No versions of macOS lack this.
+      , "libc"       -- No reasonable OSes lack this.
+      , "libdl"      -- This tends to interact with system dynamic
+                     -- linker. Bundling this may cause version
+                     -- inconsistencies.
+      , "libm"       -- No reasonable OSes lack this.
+      , "libpthread" -- No reasonable OSes lack this.
+      , "librt"      -- This tends to contain syscall wrappers.
+      ]
+
+-- Return @true@ iff the copy has actually happened.
+copyDynDep :: MonadIO m => FilePath -> FilePath -> m Bool
+copyDynDep destDir depPath =
+  if isBlockedDynDep depPath then
+    pure False
+  else
+    do let destPath = destDir -/- takeFileName depPath
+       exists <- liftIO $ IO.doesFileExist destPath
+       if exists
+         then pure False
+         else do canonSrc <- liftIO $ IO.canonicalizePath depPath -- Resolve symlinks
+                 liftIO $ IO.copyFile canonSrc destPath
+                 pure True
+
+embedRPath :: ObjectFmt -> ObjectType -> FilePath -> FilePath -> BinInfo -> FilePath -> Action ()
+embedRPath ELF _ prefix destDir bi path =
+  -- Delete any rpaths starting with $PREFIX/ and add a relative rpath to
+  -- destDir (i.e. "lib/vendor").
+  do let original = biRPaths bi
+         filtered = filter (not . (prefix `isPrefixOf`)) original
+     absDestDir <- liftIO $ IO.makeAbsolute destDir
+     absPath    <- liftIO $ IO.makeAbsolute path
+     relRPath   <- fromJust <$> liftIO (makeRelativeEx (takeDirectory absPath) absDestDir)
+     -- We must use $ORIGIN, not ${ORIGIN}, because SunOS doesn't support
+     -- the latter.
+     let normRel = dropTrailingPathSeparator . normalise $ "$ORIGIN" -/- relRPath
+         final   = intercalate [searchPathSeparator] (normRel : filtered)
+     cmd_ "patchelf" ["--set-rpath", final, path]
+
+embedRPath MachO ObjExec _ destDir bi path =
+  -- This is a Mach-O executable. Add an rpath to destDir, and replace any
+  -- references to vendored libraries with relative paths.
+  do absDestDir <- liftIO $ IO.makeAbsolute destDir
+     absPath    <- liftIO $ IO.makeAbsolute path
+     relRPath   <- fromJust <$> liftIO (makeRelativeEx (takeDirectory absPath) absDestDir)
+     let args = ["-add_rpath", "@executable_path" -/- relRPath] <> dylibChanges bi <> [path]
+     cmd_ "install_name_tool" args
+
+embedRPath MachO ObjLib _ _ bi path =
+  -- This is a Mach-O library. Change its installation path to a relative
+  -- one, and replace any references to vendored libraries with relative
+  -- paths.
+  do let args = ["-id", "@rpath" -/- takeFileName path] <> dylibChanges bi <> [path]
+     cmd_ "install_name_tool" args
+
+dylibChanges :: BinInfo -> [String]
+dylibChanges bi = concatMap change . Set.toList . biNeeded $ bi
+  where
+    change :: FilePath -> [String]
+    change depPath
+      | isBlockedDynDep depPath =
+          []
+      | otherwise =
+          ["-change", depPath, "@rpath" -/- takeFileName depPath]
