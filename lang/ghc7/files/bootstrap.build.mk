# -*- makefile-gmake -*-
#
# This is a build conf for bootstrapping compilers.
#

# We don't want any docs.
HADDOCK_DOCS       = NO
BUILD_DOCBOOK_HTML = NO
BUILD_DOCBOOK_PS   = NO
BUILD_DOCBOOK_PDF  = NO
BUILD_MAN          = NO

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

libraries/terminfo_CONFIGURE_OPTS += \
	  --configure-option=--with-curses-includes=@CURSES_PREFIX@/include \
	  --configure-option=--with-curses-libraries=@CURSES_PREFIX@/lib
