# $NetBSD: warnings.mk,v 1.1 2007/07/20 14:08:19 rillig Exp $

# This file prints the warnings that have been detected while loading
# the package Makefile. Whichever part of pkgsrc (user, package, system)
# wants to add a warning can do it by appending a properly quoted shell
# word to the WARNINGS variable.
#
# Example:
#	WARNINGS+=	"[warnings.mk] This is an example warning."
#

WARNINGS?=	# none

_show-warnings: .PHONY
.if !empty(WARNINGS:M*)
	${RUN} for w in ${WARNINGS} ; do ${ECHO} "WARNING: $$w"; done
.endif

bootstrap-depends: _show-warnings
