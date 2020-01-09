# -*- makefile-gmake -*-
#
# This is a build conf for bootstrapping compilers.
#

# We don't want any docs.
HADDOCK_DOCS       = NO
BUILD_MAN          = NO
BUILD_SPHINX_HTML  = NO
BUILD_SPHINX_PDF   = NO

# Enabling evil-splitter reduces bindist size, which is good. However
# it introduces a run-time dependency on perl, which is unacceptable.
SplitObjs          = NO

# We only want vanilla libraries and rts. No profiling, no shared
# libraries, no debugging, no event logging.
GhcLibWays         = v
GhcRTSWays         =

# I'm not sure disabling GHCi significantly reduces the bindist size,
# but we don't need it anyway.
GhcWithInterpreter = NO

# We don't want in-place GMP to be statically linked as it increases
# the bindist size. Dynamic linkage is even worse.
INTEGER_LIBRARY    = integer-simple

# We'd like to distinguish bootstrapping bindists from normal ones.
BIN_DIST_NAME      = ghc-$(ProjectVersion)-boot

# Don't build or use dynamic Haskell libraries.
DYNAMIC_GHC_PROGRAMS = NO

ghc_stage1_CONFIGURE_OPTS += -f-threaded
ghc_stage2_CONFIGURE_OPTS += -f-threaded
ghc_stage3_CONFIGURE_OPTS += -f-threaded

# We want our bootkits to be as small as possible, even though `xz
# -9e' is very slow and consumes about 680 MiB of memory.
TAR_COMP           = xz
TAR_COMP_CMD       = $(XZ_CMD) $(TAR_COMP_OPTS)
TAR_COMP_EXT       = xz
TAR_COMP_OPTS      = --verbose -9 --extreme
