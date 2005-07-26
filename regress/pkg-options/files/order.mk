# $NetBSD: order.mk,v 1.3 2005/07/26 16:12:56 dillo Exp $
#
# This file tests the effect of the PKG_DEFAULT_OPTIONS variable.
#

MAKECONF=		/dev/null

PKG_SUPPORTED_OPTIONS=	a b c d e
PKG_SUGGESTED_OPTIONS=	  b c   e
PKG_OPTIONS_VAR=	PKG_OPTIONS.unused
PKG_DEFAULT_OPTIONS=	-b b d inet6

.include "../../mk/bsd.options.mk"

.PHONY: test
test:
	echo ${PKG_FAIL_REASON:M*:Q}
	echo ${PKG_OPTIONS:Q}
