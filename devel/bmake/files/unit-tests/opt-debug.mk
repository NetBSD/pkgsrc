# $NetBSD: opt-debug.mk,v 1.2 2024/09/17 11:52:32 jperkin Exp $
#
# Tests for the -d command line option, which controls debug logging.

# Enable debug logging for the variables (var.c).
.MAKEFLAGS: -dv

VAR=	value

# Disable all debug logging again.
.MAKEFLAGS: -d0			# -d0 is available since 2020-10-03

all:
	@:;
