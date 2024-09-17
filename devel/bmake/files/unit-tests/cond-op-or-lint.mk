# $NetBSD: cond-op-or-lint.mk,v 1.2 2024/09/17 11:52:30 jperkin Exp $
#
# Tests for the || operator in .if conditions, in lint mode.

.MAKEFLAGS: -dL

# The '|' operator is not allowed in lint mode.
# It is not used in practice anyway.
# expect+1: Unknown operator '|'
.if 0 | 0
.  error
.else
.  error
.endif
