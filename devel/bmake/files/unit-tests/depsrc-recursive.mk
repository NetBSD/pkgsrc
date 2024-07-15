# $NetBSD: depsrc-recursive.mk,v 1.1 2024/07/15 09:10:14 jperkin Exp $
#
# Tests for the special source .RECURSIVE in dependency declarations,
# which executes the commands of the target even if the -n or -t command
# line options are given.

.MAKEFLAGS: -n

all: this-is-made
all: this-is-not-made

this-is-made: .RECURSIVE
	@echo ${.TARGET} is made.

this-is-not-made:
	@echo ${.TARGET} is just echoed.
