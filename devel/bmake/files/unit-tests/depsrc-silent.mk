# $NetBSD: depsrc-silent.mk,v 1.1 2024/07/15 09:10:14 jperkin Exp $
#
# Tests for the special source .SILENT in dependency declarations,
# which hides the commands, no matter whether they are prefixed with
# '@' or not.

# Without the .SILENT, the commands 'echo one' and 'echo two' would be
# written to stdout.
all: .SILENT
	echo one
	echo two
	@echo three
