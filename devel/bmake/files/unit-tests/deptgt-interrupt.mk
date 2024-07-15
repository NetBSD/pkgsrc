# $NetBSD: deptgt-interrupt.mk,v 1.1 2024/07/15 09:10:15 jperkin Exp $
#
# Tests for the special target .INTERRUPT in dependency declarations, which
# collects commands to be run when make is interrupted while building another
# target.

all:
	@kill -INT ${.MAKE.PID}

.INTERRUPT:
	@echo 'Ctrl-C'
