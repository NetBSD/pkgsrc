# $NetBSD: opt-var-literal.mk,v 1.1 2024/07/15 09:10:25 jperkin Exp $
#
# Tests for the -V command line option.

.MAKEFLAGS: -V VAR -V VALUE

VAR=	other ${VALUE} $$$$
VALUE=	value
