# $NetBSD: opt-debug-all.mk,v 1.2 2024/09/17 11:52:32 jperkin Exp $
#
# Tests for the -dA command line option, which enables all debug options
# except for -dL (lint), since that option is not related to debug logging
# but to static analysis.

# TODO: Implementation

all:
	@:;
