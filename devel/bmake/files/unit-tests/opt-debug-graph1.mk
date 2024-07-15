# $NetBSD: opt-debug-graph1.mk,v 1.1 2024/07/15 09:10:23 jperkin Exp $
#
# Tests for the -dg1 command line option, which prints the input
# graph before making anything.

.MAKEFLAGS: -dg1

all: made-target made-target-no-sources

made-target: made-source

made-source:

made-target-no-sources:

unmade-target: unmade-sources unmade-silent-source

.SILENT: unmade-silent-source

unmade-target-no-sources:

all:
	@:;
