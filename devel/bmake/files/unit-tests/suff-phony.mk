# $NetBSD: suff-phony.mk,v 1.2 2024/09/17 11:52:33 jperkin Exp $
#
# Test that .PHONY targets are not resolved using suffix rules.
#
# The purpose of the .PHONY attribute is to mark them as independent from the
# file system.
#
# See also:
#	FindDepsRegular, Ctrl+F OP_PHONY

.MAKEFLAGS: -ds

all: .PHONY

.SUFFIXES: .c

.c:
	: Making ${.TARGET} from ${.IMPSRC}.

all.c:
	: Making ${.TARGET} out of nothing.
