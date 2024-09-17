# $NetBSD: depsrc-make.mk,v 1.2 2024/09/17 11:52:30 jperkin Exp $
#
# Tests for the special source .MAKE in dependency declarations, which
# executes the commands of the target even if the -n or -t command line
# options are given.

# TODO: Add a test for the -t command line option.

.MAKEFLAGS: -n

all: this-is-made
all: this-is-not-made

this-is-made: .MAKE
	@echo ${.TARGET} is made.

this-is-not-made:
	@echo ${.TARGET} is just echoed.
