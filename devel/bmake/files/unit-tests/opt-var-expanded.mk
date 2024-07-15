# $NetBSD: opt-var-expanded.mk,v 1.1 2024/07/15 09:10:25 jperkin Exp $
#
# Tests for the -v command line option.

.MAKEFLAGS: -v VAR -v VALUE

VAR=	other ${VALUE} $$$$
VALUE=	value
