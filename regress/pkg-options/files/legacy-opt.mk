# $NetBSD: legacy-opt.mk,v 1.2 2005/05/31 13:33:39 dillo Exp $
#
# This file tests PKG_OPTIONS_LEGACY_OPTS.
#

MAKECONF=			/dev/null

PKG_OPTIONS_VAR=		PKG_OPTIONS.foo
PKG_SUPPORTED_OPTIONS=		new
PKG_OPTIONS_LEGACY_OPTS+=	old:new
PKG_OPTIONS.foo=		old

.include "../../mk/bsd.options.mk"

.PHONY: test
test:
	echo ${PKG_OPTIONS:M*:Q}
