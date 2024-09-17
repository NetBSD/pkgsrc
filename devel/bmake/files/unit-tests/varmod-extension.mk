# $NetBSD: varmod-extension.mk,v 1.2 2024/09/17 11:52:34 jperkin Exp $
#
# Tests for the :E variable modifier, which returns the filename extension
# of each word in the variable.

all:
.for path in a/b/c def a.b.c a.b/c a a.a .gitignore a a.a trailing/
	@echo "extension of '"${path:Q}"' is '"${path:E:Q}"'"
.endfor
