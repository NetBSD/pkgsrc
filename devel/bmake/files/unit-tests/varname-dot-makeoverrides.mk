# $NetBSD: varname-dot-makeoverrides.mk,v 1.2 2024/09/17 11:52:35 jperkin Exp $
#
# Tests for the special .MAKEOVERRIDES variable, which lists the names of the
# variables that are passed on to child processes via the MAKEFLAGS
# environment variable.
#
# See also:
#	varname-dot-makeflags.mk

all:
	@echo '$@: overrides=<'${.MAKEOVERRIDES:Uundefined:Q}'>'
	${MAKE} -f ${MAKEFILE} stage_1 VAR=value

stage_1:
	@echo '$@: overrides=<'${.MAKEOVERRIDES:Q}'>'
	${MAKE} -f ${MAKEFILE} stage_2 .VAR=too

stage_2:
	@echo '$@: overrides=<'${.MAKEOVERRIDES:Q}'>'
	${MAKE} -f ${MAKEFILE} stage_3

stage_3:
	@echo '$@: overrides=<'${.MAKEOVERRIDES:Q}'>'
