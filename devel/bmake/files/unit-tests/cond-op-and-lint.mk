# $NetBSD: cond-op-and-lint.mk,v 1.1 2024/07/15 09:10:12 jperkin Exp $
#
# Tests for the && operator in .if conditions, in lint mode.

.MAKEFLAGS: -dL

# The '&' operator is not allowed in lint mode.
# It is not used in practice anyway.
# expect+1: Unknown operator '&'
.if 0 & 0
.  error
.else
.  error
.endif
