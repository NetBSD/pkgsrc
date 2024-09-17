# $NetBSD: opt-x-reduce-exported.mk,v 1.2 2024/09/17 11:52:33 jperkin Exp $
#
# Tests for the -X command line option, which prevents variables passed on the
# command line from being exported to the environment of child commands.

# The variable 'BEFORE' is exported, the variable 'AFTER' isn't.
.MAKEFLAGS: BEFORE=before -X AFTER=after

all: .PHONY ordinary submake

ordinary: .PHONY
	@echo 'ordinary:'
	@env | sort | grep -e '^BEFORE' -e '^AFTER'

submake: .PHONY
	@echo 'submake:'
	@${MAKE} -r -f ${MAKEFILE} show-env

show-env: .PHONY
	@env | sort | grep -e '^BEFORE' -e '^AFTER'
