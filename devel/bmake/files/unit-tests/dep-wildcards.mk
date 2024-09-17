# $NetBSD: dep-wildcards.mk,v 1.2 2024/09/17 11:52:30 jperkin Exp $
#
# Tests for wildcards such as *.c in dependency declarations.

all: ${.PARSEDIR}/dep-*.mk
	# The :T is necessary to run this test from another directory.
	# The :O is necessary since the result of the dependency resolution
	# does not order the directory entries itself.
	@printf '%s\n' ${.ALLSRC:T:O}

# This is not a wildcard rule as implemented by GNU make, as those rules would
# use '%' instead of '*'.  Instead, the pattern '*.target' is a file pattern
# in the current working directory.  As there are no such files, the target
# list becomes empty, and the source pattern '*.source' is not even expanded.
*.target: *.source
