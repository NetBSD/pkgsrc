# $NetBSD: opt-var-literal.mk,v 1.2 2024/09/17 11:52:32 jperkin Exp $
#
# Tests for the -V command line option.

.MAKEFLAGS: -V VAR -V VALUE

VAR=	other ${VALUE} $$$$
VALUE=	value
