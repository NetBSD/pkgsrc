# $NetBSD: varname-dot-make-pid.mk,v 1.2 2024/09/17 11:52:35 jperkin Exp $
#
# Tests for the special .MAKE.PID variable, which contains the process ID of
# the make process itself.

# The process ID must be a positive integer.
.if ${.MAKE.PID:C,[0-9],,g} != ""
.  error
.elif !(${.MAKE.PID} > 0)
.  error
.endif

# Ensure that the process exists.
_!=	kill -0 ${.MAKE.PID}

all: .PHONY
