# $NetBSD: opt-debug-all.mk,v 1.1 2024/07/15 09:10:22 jperkin Exp $
#
# Tests for the -dA command line option, which enables all debug options
# except for -dL (lint), since that option is not related to debug logging
# but to static analysis.

# TODO: Implementation

all:
	@:;
