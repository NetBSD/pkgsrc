# $NetBSD: legacy-opt.mk,v 1.4 2005/07/26 16:12:56 dillo Exp $
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
	echo ${PKG_FAIL_REASON:M*:Q}
	echo ${PKG_OPTIONS:M*:Q}
