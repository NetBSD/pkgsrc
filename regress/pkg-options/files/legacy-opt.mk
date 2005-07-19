# $NetBSD: legacy-opt.mk,v 1.3 2005/07/19 10:38:19 dillo Exp $
#
# This file tests PKG_OPTIONS_LEGACY_OPTS.
#

MAKECONF=			/dev/null

PKG_OPTIONS_VAR=		PKG_OPTIONS.foo
PKG_SUPPORTED_OPTIONS=		new new2
PKG_OPTIONS_LEGACY_OPTS+=	old:new
PKG_OPTIONS_LEGACY_OPTS+=	old2:new2
PKG_OPTIONS_LEGACY_OPTS+=	old3:new3
PKG_OPTIONS.foo=		old

.include "../../mk/bsd.options.mk"

.PHONY: test
test:
	echo ${PKG_OPTIONS:M*:Q}
