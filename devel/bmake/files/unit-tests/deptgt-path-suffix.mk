# $NetBSD: deptgt-path-suffix.mk,v 1.2 2024/09/17 11:52:31 jperkin Exp $
#
# Tests for the special target .PATH.suffix in dependency declarations.

# TODO: Implementation

# expect+1: Suffix '.c' not defined (yet)
.PATH.c: ..

.SUFFIXES: .c

# Now the suffix is defined, and the path is recorded.
.PATH.c: ..

all:
	@:;
