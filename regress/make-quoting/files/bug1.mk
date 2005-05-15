# $NetBSD: bug1.mk,v 1.1 2005/05/15 22:50:13 rillig Exp $
#
# This file demonstrates a parsing bug in make(1) from NetBSD-1.6.2 and
# the current pkgsrc bmake. The make from NetBSD-2.99.15 has been fixed.
#
# The bug is that one of the closing braces is parsed twice -- once as
# terminator for a variable and once as literal character, which is
# appended to PKG_OPTIONS.

PKG_OPTIONS=	a b c
.for _o_ in -b -c
_opt_:=		${_o_}		# .for variables cannot be used in modifiers
.  if !empty(_opt_:M-*)
PKG_OPTIONS:=	${PKG_OPTIONS:N${_opt_:C/-//}} # <-- the bug
.  endif
.endfor

PASSED?=	no

# /usr/bin/make from NetBSD 2.99.15 or similar
.if !empty(MAKE_VERSION:Mnetbsd-2005*) && ${PKG_OPTIONS} == "a"
PASSED=		yes

# /usr/bin/make from NetBSD 1.6.2
.elif !empty(MAKE_VERSION:Mnetbsd-20040210) && ${PKG_OPTIONS} == "a b c}}"
PASSED=		yes

# bmake from pkgsrc
.elif !empty(MAKE_VERSION:Mbmake-3.1.12*) && ${PKG_OPTIONS} == "a b c}}"
PASSED=		yes

.endif

.PHONY: all
all:
	@echo ${PASSED}
