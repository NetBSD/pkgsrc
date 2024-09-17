# $NetBSD: varname-dot-objdir.mk,v 1.2 2024/09/17 11:52:35 jperkin Exp $
#
# Tests for the special .OBJDIR variable.

# TODO: Implementation

all:
	# Add an entry to the cached_realpath table, to test cleaning up
	# that table in purge_relative_cached_realpaths.
	# Having a ':=' assignment in the command line is construed but works
	# well enough to reach the code.
	@${MAKE} -f ${MAKEFILE} 'VAR:=$${:U.:tA}' purge-cache

purge-cache:
	: ${.TARGET} was reached.
