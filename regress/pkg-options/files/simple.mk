# $NetBSD: simple.mk,v 1.2 2005/05/31 13:33:39 dillo Exp $
#
# This file tests a very simple options configuration.
#

MAKECONF=		/dev/null

PKG_SUPPORTED_OPTIONS=	a b c d e
PKG_SUGGESTED_OPTIONS=	  b c   e
PKG_OPTIONS_VAR=	PKG_OPTIONS.unused

.include "../../mk/bsd.options.mk"

.PHONY: test
test:
	echo ${PKG_OPTIONS:M*:Q}
