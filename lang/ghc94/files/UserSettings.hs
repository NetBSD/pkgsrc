-- $NetBSD: UserSettings.hs,v 1.1 2023/01/21 04:49:25 pho Exp $
--
-- This is a Hadrian settings file to override some defaults in a way which
-- isn't possible through command-line options. It is only used during the
-- build of bootkits. Options for regular builds are passed via command
-- line.

module UserSettings (
    userFlavours, userPackages, userDefaultFlavour,
    verboseCommand, buildProgressColour, successColour, finalStage
    ) where

import Flavour.Type
import Expression
import {-# SOURCE #-} Settings.Default

-- See ${WRKSRIC}/hadrian/doc/user-settings.md for instructions.

userDefaultFlavour :: String
userDefaultFlavour = "default"

userFlavours :: [Flavour]
userFlavours = [bootkitFlavour]

-- It is preferred to use this flavour with "split_sections" transformer,
-- e.g. --flavour=bootkit+split_sections
bootkitFlavour :: Flavour
bootkitFlavour =
  defaultFlavour
  { name               = "bootkit"
    -- We don't want in-tree GMP to be statically linked as it increases
    -- the bindist size. Dynamic linkage is even worse.
  , bignumBackend      = "native"
    -- We only want vanilla libraries and RTS. No profiling, no shared
    -- libraries, no debugging.
  , libraryWays        = pure [vanilla]
  , rtsWays            = pure [vanilla]
    -- Don't build or use dynamic Haskell libraries.
  , dynamicGhcPrograms = pure False
    -- Build GHC as minimally as possible.
  , ghciWithDebugger   = False
  , ghcProfiled        = False
  , ghcDebugged        = False
  , ghcDebugAssertions = False
  , ghcThreaded        = False
    -- This is a bootstrap compiler. We don't want any kinds of
    -- documentation.
  , ghcDocs            = pure mempty
  }

userPackages :: [Package]
userPackages = []

verboseCommand :: Predicate
verboseCommand = do
    verbosity <- expr getVerbosity
    return $ verbosity >= Verbose

buildProgressColour :: BuildProgressColour
buildProgressColour = mkBuildProgressColour (Dull Magenta)

successColour :: SuccessColour
successColour = mkSuccessColour (Dull Green)

finalStage :: Stage
finalStage = Stage2
