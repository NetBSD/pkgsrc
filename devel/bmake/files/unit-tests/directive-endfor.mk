# $NetBSD: directive-endfor.mk,v 1.1 2024/07/15 09:10:17 jperkin Exp $
#
# Test for the directive .endfor, which ends a .for loop.
#
# See also:
#	directive-for.mk

# An .endfor without a corresponding .for is a parse error.
# expect+1: for-less endfor
.endfor
