# $NetBSD: deptgt-main.mk,v 1.2 2024/09/17 11:52:30 jperkin Exp $
#
# Tests for the special target .MAIN in dependency declarations, which defines
# the main target.  This main target is built if no target has been specified
# on the command line or via MAKEFLAGS.

# The first target becomes the main target by default.  It can be overridden
# though.
all: .PHONY
	@echo 'This target is not made.'

# This target is not the first to be defined, but it lists '.MAIN' as one of
# its sources.  The word '.MAIN' only has a special meaning when it appears as
# a _target_ in a dependency declaration, not as a _source_.  It is thus
# ignored.
depsrc-main: .PHONY .MAIN
	@echo 'This target is not made either.'

# This target is the first to be marked with '.MAIN', so it replaces the
# previous main target, which was 'all'.
.MAIN: real-main
real-main: .PHONY
	@echo 'This target ${.TARGET} is the one that is made.'

# This target is marked with '.MAIN' but there already is a main target.  The
# attribute '.MAIN' is thus ignored.
.MAIN: too-late
too-late: .PHONY
	@echo 'This target comes too late, there is already a .MAIN target.'
