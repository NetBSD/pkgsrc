# $NetBSD: dep-colon.mk,v 1.2 2024/09/17 11:52:30 jperkin Exp $
#
# Tests for the : operator in dependency declarations.

# TODO: Implementation

# In a dependency declaration line, there may be a shell command after the
# sources.  It is separated by a semicolon.  This "feature" is required by
# POSIX.  It is seldom used, if at all.
all: target1
target1: source1; @echo making ${.TARGET} from ${.ALLSRC}
source1: .PHONY

# The semicolon for separating the sources from the creation commands must
# appear at the top-level.  The semicolons inside the :S;1;2; modifier are
# skipped when looking for the semicolon that separates the sources from
# the commands.
all: target2
target2: source${:U1:S;1;2;}; @echo making ${.TARGET} from ${.ALLSRC}
source2: .PHONY
