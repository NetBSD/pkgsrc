# $NetBSD: opt-var-expanded.mk,v 1.2 2024/09/17 11:52:32 jperkin Exp $
#
# Tests for the -v command line option.

.MAKEFLAGS: -v VAR -v VALUE

VAR=	other ${VALUE} $$$$
VALUE=	value
