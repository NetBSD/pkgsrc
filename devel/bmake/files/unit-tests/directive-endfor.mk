# $NetBSD: directive-endfor.mk,v 1.2 2024/09/17 11:52:31 jperkin Exp $
#
# Test for the directive .endfor, which ends a .for loop.
#
# See also:
#	directive-for.mk

# An .endfor without a corresponding .for is a parse error.
# expect+1: for-less endfor
.endfor
