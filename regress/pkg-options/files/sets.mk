# $NetBSD: sets.mk,v 1.1 2005/07/26 09:00:42 dillo Exp $
#
# This file tests non-empty option sets (PKG_OPTIONS_NONEMPTY_SETS).
#

MAKECONF=			/dev/null

PKG_OPTIONS_VAR=		PKG_OPTIONS.foo
PKG_SUPPORTED_OPTIONS=		single
PKG_OPTIONS_NONEMPTY_SETS=	abc def
PKG_OPTIONS_SET.abc=		a b c
PKG_OPTIONS_SET.def=		d e f

PKG_OPTIONS.foo=	a

.include "../../mk/bsd.options.mk"

.PHONY: test
test:
	echo ${PKG_FAIL_REASON:Q}
