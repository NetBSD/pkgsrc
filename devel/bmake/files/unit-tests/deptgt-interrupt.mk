# $NetBSD: deptgt-interrupt.mk,v 1.2 2024/09/17 11:52:30 jperkin Exp $
#
# Tests for the special target .INTERRUPT in dependency declarations, which
# collects commands to be run when make is interrupted while building another
# target.

all:
	@kill -INT ${.MAKE.PID}

.INTERRUPT:
	@echo 'Ctrl-C'
