# $NetBSD: unsupported.mk,v 1.2 2005/05/31 13:33:39 dillo Exp $
#
# This file tests that selecting unsupported options in PKG_OPTIONS.foo
# causes the package build to fail.
#

MAKECONF=		/dev/null

PKG_SUPPORTED_OPTIONS=	a
PKG_SUGGESTED_OPTIONS=	
PKG_OPTIONS_VAR=	PKG_OPTIONS.foo
PKG_DEFAULT_OPTIONS=	
PKG_OPTIONS.foo=	b c

.include "../../mk/bsd.options.mk"

.PHONY: test
test:
	echo ${PKG_FAIL_REASON:Q}
